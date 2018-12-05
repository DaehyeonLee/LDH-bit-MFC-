#include "stdafx.h"

CObject* CRuntimeClass::CreateObject() {
	return (*pfnCreateObject)();
	//CRuntimeClass 구조체의 CreateObject() 정의
}