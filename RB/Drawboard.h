#pragma once
//#include <windows.h>
#include "RBTree.h"
/* This struct includes WinMain and RB_Tree information to draw node on board. */
typedef struct _nodeposition {
	int		cX, cY; /* These are position of new node when edit control gets a value. */
	int		nX, nY; /* These are next position that new node will get to show moving node in window display. */
	int		dX, dY;	/* These are distance between parent and child node. These can change when a new node insert in the tree. */
	int		size_node;
	int		cnt;
}NodePos;
typedef struct _drawboardinfo {
	HWND	hWnd;
	TCHAR	str_edit_input[128];
	BOOL	b_flag_eidt_input;

	NodePos node;
	RB_NODE * root;
}DrawInfo;

void InitialInfo(DrawInfo *);
void DrawBoard(DrawInfo *, HDC);
void MoveLine(HDC, int, int, int, int);
void EraseNode(DrawInfo *);
void Insert_Node(DrawInfo *);
void Erase_Node(DrawInfo *);