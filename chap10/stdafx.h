#pragma once
//window용 , macro 정의
#include <windows.h>
#ifndef _stdafx_defined_
#define _stdafx_defiened_

#define DECLARE_MESSAGE_MAP() static MessageMap messageMap[]; //메세지와 함수를 매핑해주는 배열
#define BEGIN_MESSAGE_MAP(class_name) MessageMap class_name::messageMap[] = {
#define END_MESSAGE_MAP() {0,NULL}};

#define RUNTIME_CLASS(class_name) (&class_name::class##class_name) //
#define DECLARE_DYNAMIC(class_name) static CRuntimeClass class##class_name; //클래스에 관련된 static 구조체 변수
#define IMPLEMENT_DYNAMIC(class_name) CRuntimeClass class_name::class##class_name = { (#class_name), sizeof(class_name), class_name::CreateObject};
// 구조체 초기화
#define DECLARE_DYNCREATE(class_name) DECLARE_DYNAMIC(class_name) static CObject* CreateObject();
//변수선언, 함수선언
#define IMPLEMENT_DYNCREATE(class_name) IMPLEMENT_DYNAMIC(class_name) CObject* class_name::CreateObject() {return new class_name;}
//변수 초기화, 함수 정의
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

class CObject; //어딘가에선언이 되어있다고알려준다.

struct CRuntimeClass {
	char m_lpszClassName[21];
	int m_nobjectSize; //바운더리 지정
	CObject* (*pfnCreateObject)();
	CObject* CreateObject();
};

class CView;
typedef void(CView::*CViewFunPointer)(); //메세지맵 함수 포인터 선언
typedef struct tagMessageMap {
	UINT iMsg; //메세지번호
	CViewFunPointer fp;
}MessageMap;
#endif