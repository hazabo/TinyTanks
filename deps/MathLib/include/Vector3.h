//\==================================================================
//\
//\ Author: Harry Woolford
//\	File: Vector3.h
//\
//\==================================================================

#pragma once

#ifndef __VECTOR3_H__
#define __VECTOR3_H__

#include "mathLib.h"

//\==================================================================
//\
//\ Declaration of a Vector 3 class
//\
//\==================================================================

class DLLEXPORT Vector3
{
public:

	//\==================================================================
	//\ Constructors
	//\==================================================================
	Vector3();
	Vector3(float a_x, float a_y, float a_z);
	Vector3(const Vector3& a_v3);
	//\==================================================================
	//\ Destructor
	//\==================================================================
	~Vector3();
	//\==================================================================
	//\ Addition and subraction operators
	//\==================================================================
	Vector3		operator +		(const Vector3& a_v3) const;
	Vector3&	operator +=		(const Vector3& a_v3);
	Vector3		operator -		(const Vector3& a_v3) const;
	Vector3&	operator -=		(const Vector3& a_v3);
	//\==================================================================
	//\ Equivalence operators
	//\==================================================================
	bool		operator ==		(const Vector3& a_v3) const;
	bool		operator !=		(const Vector3& a_v3) const;
	//\==================================================================
	//\ multiplication operators
	//\==================================================================
	Vector3&    operator *      (const float& a_f);
	Vector3&    operator *      (const int& a_f);
	Vector3&    operator *      (const double& a_f);
	//\==================================================================
	//\ Division operators
	//\==================================================================
	Vector3&    operator /      (const float& a_f);
	Vector3&    operator /      (const int& a_f);
	Vector3&    operator /      (const double& a_f);
	//\==================================================================
	//\ Dot Product
	//\==================================================================
	float       dot				(const Vector3& a_v3)const;
	//\==================================================================
	//\ Cross Product
	//\==================================================================
	Vector3     cross			(const Vector3& a_v3)const;
	//\==================================================================
	//\ Rotation Functions
	//\==================================================================
	void		RotateX			(float a_fAngle);
	void		RotateY			(float a_fAngle);
	void		RotateZ			(float a_fAngle);
	//\==================================================================
	//\ Magnitude 
	//\==================================================================
	float		Magnitude		() const;
	float		SquareMagnitude () const;


	float x;
	float y;
	float z;

};

#endif //__VECTOR2_H__
