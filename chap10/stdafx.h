#pragma once
//window�� , macro ����
#include <windows.h>
#ifndef _stdafx_defined_
#define _stdafx_defiened_

#define DECLARE_MESSAGE_MAP() static MessageMap messageMap[]; //�޼����� �Լ��� �������ִ� �迭
#define BEGIN_MESSAGE_MAP(class_name) MessageMap class_name::messageMap[] = {
#define END_MESSAGE_MAP() {0,NULL}};

#define RUNTIME_CLASS(class_name) (&class_name::class##class_name) //
#define DECLARE_DYNAMIC(class_name) static CRuntimeClass class##class_name; //Ŭ������ ���õ� static ����ü ����
#define IMPLEMENT_DYNAMIC(class_name) CRuntimeClass class_name::class##class_name = { (#class_name), sizeof(class_name), class_name::CreateObject};
// ����ü �ʱ�ȭ
#define DECLARE_DYNCREATE(class_name) DECLARE_DYNAMIC(class_name) static CObject* CreateObject();
//��������, �Լ�����
#define IMPLEMENT_DYNCREATE(class_name) IMPLEMENT_DYNAMIC(class_name) CObject* class_name::CreateObject() {return new class_name;}
//���� �ʱ�ȭ, �Լ� ����
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

class CObject; //��򰡿������� �Ǿ��ִٰ�˷��ش�.

struct CRuntimeClass {
	char m_lpszClassName[21];
	int m_nobjectSize; //�ٿ���� ����
	CObject* (*pfnCreateObject)();
	CObject* CreateObject();
};

class CView;
typedef void(CView::*CViewFunPointer)(); //�޼����� �Լ� ������ ����
typedef struct tagMessageMap {
	UINT iMsg; //�޼�����ȣ
	CViewFunPointer fp;
}MessageMap;
#endif