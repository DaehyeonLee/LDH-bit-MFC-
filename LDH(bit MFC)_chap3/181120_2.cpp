#include <iostream>
using namespace std;

#if 0
#include <stdio.h>

#define PI 3.141592
#define A  B,C
#define begin {
#define end }
#define procedure void

int b = 1, c = 2;

procedure PrintPI()
begin
printf("%f\n", PI);
end
void main()
begin
PrintPI();
printf("%d, %d\n", A);
end
#endif

#if 0
#define DEBUG

#ifdef DEBUG //���ǰ� ��ٸ� ���̰� ���ǰ� �ȵǸ� ����

void f(int i) {
	printf("%d\n", i);
}
#endif
void main() {
	int i = 3, j = 3, k = 4;
	k = i * j * k;
#undef DEBUG //define ����
#ifdef DEBUG
	f(k);
#endif
	printf("%d,%d,%d\n", i, j, k);
}
#endif

#if 0
void main() {
	int i = 2, j = 3, k = 4;

	printf("%d,%d,%d\n", i, j, k);
	printf("%d\n", __LINE__); //���� ���� ���
	printf("%s\n", __FILE__); //�ҽ������� ��ġ
}
#endif

#if 0
void main() {
#line 1 "main.cpp"
	int i = 2, j = 3, k = 4; //1�� �������� ����.
	printf("%d,%d,%d\n", i, j, k);
	printf("%s,%d\n", __FILE__, __LINE__);
	printf("%d\n", __LINE__);
#line 3897 "test.cpp"
	printf("%s,%d\n", __FILE__, __LINE__);
}
#endif

#if 0
#define TYPE 1
/*
	TYPE 0 : WIN
	TYPE 1 : LINUX
*/
void main() {
	int  i = 2, j = 3;
#if(TYPE!=0)
#error used LINUX COMMAND CP, please change window environment
	//error �޼��� ����ϱ�
#endif
	printf("%d,%d\n", i, j);
}
#endif 

#if 0
void main() {
	printf("hello\n");
#pragma message("between hello and world\n") //��� â�� display�ȴ�.
	printf("world\n");
}
#endif

#if 0
#define LINE1(x) #x
#define LINE(x) LINE1(x)
#define TODO(msg) message(__FILE__"(" LINE(__LINE__) "):[TODO]" msg)

void main() {
#pragma TODO ( "implement main()\n")
	printf("hello\n");
	printf("world\n");
	//printf("hello" "world"); ���ڿ� �������� �����ϸ� ���ڿ��� �ٴ´�
	//define TODO������ �̷��� ����� ����ߴ�.
}
#endif

#if 1
#pragma warning(disable:4996)

#include<stdio.h>
#include "MyAfx.h"

//�������ִ� ������ ��ġ�� �˷��ֱ� ���ؼ� THIS_FILE�� �����̸��� �־�����(���絹�ư�������)
//������ �����Ϸ��� �����ؼ� ����Ͽ��� ������ ������ �˾Ƽ� �˷��ش�.
static char _szAfxVectorInl[] = "VectorCpp.inl";
#undef THIS_FILE
#define THIS_FILE _szAfxVectorInl

#if defined(__cplusplus)
struct CVector2 {
#elif 
typedef struct CVector2 {
#endif
	float  _x;
	float  _y;

#if defined(__cplusplus)
#include "VectorCpp.inl"
#endif
#if defined(__cplusplus)
};
#elif

}CVector2;

#endif

#undef THIS_FILE
#define THIS_FILE __FILE__

void Test(CVector2 v) {

	printf("(%g,%g)\n", v._x, v._y);
	ASSERT(0)

}

int main() {
#if defined(__cplusplus) //c++�� �����ϵɶ�

	CVector2 v(0.f, 0.f);
	CVector2 v2(1.f, 1.f);
	CVector2 v3(2.f, 2.f);
	v = v2 + v3;
#else //C�� ������ �ɶ�
	CVector2 v;
	CVector2 v2;
	CVector2 v3;

	v._x = v._y = 0.f;
	v2._x = v2._y = 1.f;
	v3._x = v3._y = 2.f;

	v._x = v2._x = v3._x;
	v._y = v2._y = v3._y;
#endif
	Test(v);
}
#endif



