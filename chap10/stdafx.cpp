#include "stdafx.h"

CObject* CRuntimeClass::CreateObject() {
	return (*pfnCreateObject)();
	//CRuntimeClass ����ü�� CreateObject() ����
}