// ===========================================================================
//  stringFile.h
//  Reduce3D
//
//  Created by David Hirsch on 11/29/07.
//  Copyright 2011 David Hirsch.
//  Distributed under the terms of the GNU General Public License v3
//	See file "COPYING for more info.
//
/*	There's a bunch of extra hassle here, due to the need to make this header be free of Objective-C and Cocoa so that it can be included by C++ files.  Most of this uses the "toll-free bridging" of the NS and the CF classes. The implementation uses a combination of CF functions and NS functions to do the actual work.  The methods were tested with the NS versions and then altered to CF versions later. */
// ===========================================================================

#import <string>
#include <CoreFoundation/CoreFoundation.h>

class stringFile {
public:
	class UnexpectedEOF {
		public:
		std::string filename;
	};

	stringFile();
	stringFile(bool inForOutput, const char *inPath, bool inWriteAsap=false);
	stringFile(bool inForOutput, CFStringRef inPath, bool inWriteAsap=false);
	~stringFile();
	void setIsForOutput(bool inForOutput);

	// File manipulation methods
	void setPath(CFStringRef inPath);
	void setPath(char *inPath);
	CFStringRef getPath();
	std::string getName();
	std::string getNameWithoutExtension();
	void setName(CFStringRef inName);
	void setName(char *inName);
	void copyPath(stringFile *inStringFile);

	// Text I/O methods
	bool syncWithFile();	// this will overwrite any existing file at the path, if we are set to output mode
	std::string		getOneLine();
	std::string		peekLine();
	void			putOneLine(std::string *inStr);
	void			putOneLine(const char *inStr);
	void			putOneLine(CFStringRef inStr);

protected:
	bool writeToFile();
	bool readFromFile();
	
private:
	CFArrayRef mLines;	// an array of NSStrings, one per line
	CFStringRef	path;	// path to the filename associated with this object.  The file at that path
						// may or may not exist.
	void *mFileHandle;	// used only if we are writing asap instead of all at once at deallocation
	long		mCurLine;	// what line we're ready to read from (for input files)
	bool		mForOutput;	// the file is desginated for saving (or for reading)
	bool		mWriteAsap;	// should we write to the file as soon as we get a string, or hold it until writeToFile is called?
};
