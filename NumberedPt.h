// ===========================================================================//	NumberedPt.h// ===========================================================================#pragma once#include "Point3DFloat.h"class NumberedPt : public Point3DFloat {	public:						NumberedPt();						NumberedPt(short inSeq, float inX, float inY, float inZ);						NumberedPt(NumberedPt &inPt);						NumberedPt(Point3DFloat &inPt);		NumberedPt	&operator= (NumberedPt &inPt);		NumberedPt	&operator= (Point3DFloat &inPt);		Boolean		operator== (NumberedPt &inPt);		Boolean		operator!= (NumberedPt &inPt);				public:		// I'm making these public, in violation of good style,					// in order to keep function calls to a minimum		short seq;};