#include <stdio.h>
#include "macro.h"
//#include "b.cpp"

//extern int f(int i); //f�Լ��� �ۿ��ִ�.

int f(int i) {
	PRINT(i);
	return i * i * i;
}

int main() {
	int i;
	i = f(2);
	PRINT(i);
	return 0;
}