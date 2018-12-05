
// LDH(bit MFC)_chap7.h: LDH(bit MFC)_chap7 응용 프로그램의 기본 헤더 파일
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH에 대해 이 파일을 포함하기 전에 'stdafx.h'를 포함합니다."
#endif

#include "resource.h"       // 주 기호입니다.


// CLDHbitMFCchap7App:
// 이 클래스의 구현에 대해서는 LDH(bit MFC)_chap7.cpp을(를) 참조하세요.
//

class CLDHbitMFCchap7App : public CWinApp //CWinApp 상속받음
{
public:
	CLDHbitMFCchap7App() noexcept;


// 재정의입니다.
public:
	virtual BOOL InitInstance();

// 구현입니다.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP() //static변수선언
};

extern CLDHbitMFCchap7App theApp;
