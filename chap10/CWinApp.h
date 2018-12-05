#pragma once

#include "stdafx.h"

#include "CObject.h"

#include "CView.h"



class CWinApp :public CObject {

protected:

	static char szAppName[];

	HINSTANCE m_hInstance;

public:

	CWnd*	m_pMainWnd;



public:

	virtual ~CWinApp();

	void AddDocTemplate(CRuntimeClass* pRuntimeClass);

	void InitInstance(HINSTANCE hInstance, PSTR szCmdLine, int iCmdShow);



	void Run();

	WPARAM ExitInstance();



	virtual int OnIdle();

};