#pragma once
#include "stdafx.h"

#ifndef _CObject_
#define _CObject_
class CObject {
public:
	virtual CRuntimeClass* GetRuntimeClass() const;
	virtual ~CObject(){}

protected:
	CObject(){}
};
#endif