#if 0
#pragma warning(disable:4996)

#include<stdio.h>
#include "MyAfx.h"

//오류가있는 파일의 위치를 알려주기 위해서 THIS_FILE에 파일이름을 넣었었다(현재돌아가는파일)
//지금은 컴파일러가 발전해서 어떤파일에서 오류가 나는지 알아서 알려준다.
static char _szAfxVectorInl[] = "VectorCpp.inl";
#undef THIS_FILE
#define THIS_FILE _szAfxVectorInl

#if defined(__cplusplus)
struct CVector2 {
#else 
typedef struct CVector2 {
#endif
	float  _x;
	float  _y;

#if defined(__cplusplus)
#include "VectorCpp.inl"
#endif
#if defined(__cplusplus)
};
#else
}CVector2;
#endif

#undef THIS_FILE
#define THIS_FILE __FILE__

void Test(CVector2 v) {

	printf("(%g,%g)\n", v._x, v._y);
	ASSERT(0)

}

int main() {
#if defined(__cplusplus) //c++로 컴파일될때

	CVector2 v(0.f, 0.f);
	CVector2 v2(1.f, 1.f);
	CVector2 v3(2.f, 2.f);
	v = v2 + v3;
#else //C로 컴파일 될때
	CVector2 v;
	CVector2 v2;
	CVector2 v3;

	v._x = v._y = 0.f;
	v2._x = v2._y = 1.f;
	v3._x = v3._y = 2.f;

	v._x = v2._x + v3._x;
	v._y = v2._y + v3._y;
#endif
	Test(v);
}
#endif
