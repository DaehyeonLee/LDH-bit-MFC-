//#pragma once
#include<stdio.h>
#include "MyAfx.h"

#ifndef _VECTORCPP_INL
#define _VECTORCPP_INL

CVector2( float x, float y) { //»ý¼ºÀÚ
	_x = x; 
	_y = y;
}
CVector2 operator+(CVector2 r) {
	CVector2 temp(_x + r._x, _y + r._y);
	ASSERT(0);
	return temp;
}
#endif