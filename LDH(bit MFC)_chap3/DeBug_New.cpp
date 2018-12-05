#if 1
#include <stdio.h>
#include <stdlib.h>
#include "DeBug_New.h"

#if defined(_DEBUG)
#define new DEBUG_NEW
#endif

void main() {
	int *p = new int();
	*p = 1;
	printf("%i\n", *p);

	delete p;
}
#endif