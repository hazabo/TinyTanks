//\==================================================================
//\
//\ Author: Harry Woolford
//\	File: Vector2.h
//\
//\==================================================================

#pragma once

#ifndef __VECTOR2_H__
#define __VECTOR2_H__

#include "mathLib.h"

//\==================================================================
//\
//\	Declaration of a Vector 2 class
//\
//\==================================================================


class DLLEXPORT Vector2
{
public:
	//\==================================================================
	//\ Constructors
	//\==================================================================
	Vector2();
	Vector2(float a_x, float a_y);
	Vector2(const Vector2& a_v2);
	//\==================================================================
	//\ Destructor
	//\==================================================================
	~Vector2();
	//\==================================================================
	//\ Addition and subtraction operators 
	//\==================================================================
	Vector2		operator +		(const Vector2& a_v2) const;
	Vector2&	operator +=		(const Vector2& a_v2);
	Vector2		operator -		(const Vector2& a_v2) const;
	Vector2&	operator -=		(const Vector2& a_v2);
	//\==================================================================
	//\ Equivalence operators 
	//\==================================================================
	bool		operator ==		(const Vector2& a_v2) const;
	bool		operator !=		(const Vector2& a_v2) const;
	//\==================================================================
	//\ Multiplication operators
	//\==================================================================
	Vector2		operator *      (const float a_f)const;
	Vector2&	operator *=		(const float a_f);
	Vector2		operator *		(const Vector2& a_v2)const;
	Vector2&	operator *=		(const Vector2& a_v2);
	//\==================================================================
	//\ Division operators
	//\==================================================================
	Vector2		operator /      (const float a_f)const;
	Vector2&	operator /=		(const float a_f);
	Vector2		operator /		(const Vector2& a_v2)const;
	Vector2&	operator /=		(const Vector2& a_v2);
	//\==================================================================
	//\ Rotation
	//\==================================================================
	void		Rotate			(float f_angle);
	//\==================================================================
	//\ Magnitude functions
	//\==================================================================
	float		MagnitudeSquared()const;
	float		Magnitude()const;
	//\==================================================================
	//\ Dot product
	//\==================================================================
	float       dot(const Vector2& a_v2)const;

	float x;
	float y;

};

#endif //__VECTOR2_H__