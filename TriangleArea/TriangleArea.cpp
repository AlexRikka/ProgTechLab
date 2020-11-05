// TriangleArea.cpp: определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"
#include <cmath> 

#define LIB_EXPORT
#include "TriangleArea.h"
double TriangleArea(int* vx)
{
	return abs(vx[0]*(vx[3] - vx[5]) + vx[2]*(vx[5] - vx[1]) + vx[4]*(vx[1] - vx[3]))/2.0;
}              


