#include "CWnd.h"

IMPLEMENT_DYNCREATE(CWnd)
HWND CWnd::GetSafeHwnd() { return this == NULL ? NULL : m_hwnd; }
BOOL CWnd::ShowWindow(int nCmdShow) { return ::ShowWindow(GetSafeHwnd(), nCmdShow); }
BOOL CWnd::UpdateWindow() { return ::UpdateWindow(GetSafeHwnd()); }
void CWnd::PreCreateWindow(CREATESTRUCT &cs){}