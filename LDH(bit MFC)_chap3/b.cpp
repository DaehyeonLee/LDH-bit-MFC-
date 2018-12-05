#include "macro.h"
#include <stdio.h>

int f(int i) {
	PRINT(i);
	return i * i * i;
}