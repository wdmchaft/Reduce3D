// ===========================================================================//	Side.h// ===========================================================================#pragma once#include "NumberedPt.h"// ---------------------------------------------------------------------------//		� Side// ---------------------------------------------------------------------------class	Side {	public:						Side();						Side(Side &inSide);		virtual			~Side();		float			Area();		Point3DFloat	& AwayVect(Point3DFloat &inPt);		Point3DFloat	&Vect12to3();		void			MakeInVect(Point3DFloat &inCtr);		Boolean			PointOnSide(Point3DFloat &inPt);	public:		NumberedPt		pt1, pt2, pt3;		Boolean			edge1, edge2, edge3;		Point3DFloat	inVect;};