
/**
* DLL Export Define
* - This is a define for building this library as a DLL or as a static library
* - The syntax and meaning of this will be covered in class when we are covering
*   building a math library
**/
#ifdef MATH_DLL_BUILD
#define DLLEXPORT __declspec(dllexport)
#elif MATH_DLL
#define DLLEXPORT __declspec(dllimport)
#else
#define DLLEXPORT 
#endif

#ifndef __MATHLIB_H__
#define __MATHLIB_H__

#define _USE_MATH_DEFINES
#include <math.h>
#include "Vector2.h"
#include "Vector3.h"
#include "Matrix3.h"


#endif // !__MATHLIB_H__

// TODO: reference additional headers your program requires here
