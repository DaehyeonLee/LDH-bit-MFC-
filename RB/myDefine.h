#pragma once
#include<Windows.h>
#define IDC_BUTTON_INSERT		(WM_USER+1)
#define IDC_BUTTON_DELETE		(WM_USER+2)
#define IDC_EDIT_INPUT				(WM_USER+3)
#define IDC_TIMER_INSERT			(WM_USER+4)
#define NEW_NODE_POS_X			200
#define NEW_NODE_POS_Y			10
#define ENTRY_NODE_POS_X		400
#define ENTRY_NODE_POS_Y		10
#define INITIAL_NODE_SIZE			50		/* The initial size of node get this value and the initial size of node can change later. */
static HWND hEdit_Input;