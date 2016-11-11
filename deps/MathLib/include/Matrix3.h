#pragma once

#ifndef __MATRIX3_H__
#define __MATRIX3_H__

#include "MathLib.h"

class DLLEXPORT Matrix3
{
public:
	Matrix3();
	Matrix3(float a_11, float a_12, float a_13,
		float a_21, float a_22, float a_23,
		float a_31, float a_32, float a_33);
	Matrix3(const Matrix3& a_m3);
	~Matrix3();
	/*
	void CreateIdentity();
	void CreateRotation();
	void CreateTranslation();

	Matrix3 GetTranslations();
	Matrix3 GetRotation();
	
	void SetTranslation();
	void SetRotation();

	void TransformVector();
	void TransformPoint();

	*/
	//\==================================================================
	//\ Addition and subraction operations
	//\==================================================================
	Matrix3		operator +		(const Matrix3& a_m3) const;
	Matrix3&	operator +=		(const Matrix3& a_m3);
	Matrix3		operator -		(const Matrix3& a_m3) const;
	Matrix3&	operator -=		(const Matrix3& a_m3);
	//\==================================================================
	//\ Equivalence operations
	//\==================================================================
	bool		operator ==		(const Matrix3& a_m3) const;
	bool		operator !=		(const Matrix3& a_m3) const;
	//\==================================================================
	//\ Multiplication operations
	//\==================================================================
	Matrix3		operator *		(const float a_scalar) const;
	Matrix3		operator *=		(const float a_scalar);
	Vector3		operator *		(const Vector3& a_v3) const;
	Matrix3     operator *		(const Matrix3& a_m3) const;
	Matrix3     operator *=		(const Matrix3& a_m3);

	float		determinant		();
	
	Matrix3		inverse			();







	float element[9];
};




#endif //__MATRIX3_H__