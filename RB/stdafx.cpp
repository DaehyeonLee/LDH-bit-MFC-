#include "stdafx.h"
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "RBTree.h"
#include "Drawboard.h"
#include "myDefine.h"

// stdafx.cpp : 표준 포함 파일만 들어 있는 소스 파일입니다.
// RB.pch는 미리 컴파일된 헤더가 됩니다.
// stdafx.obj에는 미리 컴파일된 형식 정보가 포함됩니다.

void __erase_data_color(RB_NODE * n, RB_NODE * p, RB_NODE ** dpn)
{
	RB_NODE * s, *x, *y;
	while ((!n || RB_IS_BLACK(n)) && (n != *dpn)) {
		/*
		* Loop invariants:
		* - node is black (or NULL on first iteration)
		* - node is not the root (parent is not NULL)
		* - All leaf paths going through parent and node have a
		*   black node count that is 1 lower than other leaf paths.
		*/
		s = p->right;
		if (s != n) /* n == parent->left */ {
			if (RB_IS_RED(s)) {
				/*
				* Case 1 - left rotate at parent
				*
				*     P                 S
				*     / \                / \
				*   N   s     -->   p   Y
				*        / \          / \
				*      X   Y      N   X
				*/
				x = s->left;
				RB_SET_RED(p);
				RB_SET_BLACK(s);
				rotate_left(p, dpn);
				s = x;
			}
			y = s->right;
			if (!y || RB_IS_BLACK(y)) { /* This part includes Case:2 and Case:3. */
				x = s->left;
				if (!x || RB_IS_BLACK(x)) {
					/*
					* Case 2 - sibling color flip
					* (p could be either color here)
					*
					*    (p)             (p)
					*    /  \             / \
					*   N  S    -->  N  s
					*       / \             / \
					*      X  Y          X  Y
					*
					* This leaves us violating 5) which
					* can be fixed by flipping p to black
					* if it was red, or by recursing at p.
					* p is red when coming from Case 1.
					*/
					RB_SET_RED(s);
					if (RB_IS_BLACK(p))   /* Case 2-1 */
					{
						n = p;
						p = RB_PARENT(n);
						if (p)      continue;
					}
					else      RB_SET_BLACK(p);   /* Case 2-2 */
					break;
				}
				/*
				* Case 3 - right rotate at sibling
				* (p could be either color here)
				*
				*    (p)             (p)
				*    / \              / \
				*  N  S    -->   N  x
				*      / \                 \
				*     x  Y               S
				*                            \
				*                            Y
				*/
				RB_SET_RED(s);
				RB_SET_BLACK(x);
				rotate_right(s, dpn);
				y = s;
				s = x;
			}
			/*
			* Case 4 - left rotate at parent + color flips
			* (p and sl could be either color here.
			*  After rotation, p becomes black, s acquires
			*  p's color, and sl keeps its color)
			*
			*      (p)                 (s)
			*      / \                  / \
			*     N   S     -->   P   Sr
			*          / \           / \
			*       (sl) sr       N  (sl)
			*/
			x = s->left;
			RB_SET_BLACK(y);
			RB_SET_COLOR(s, p);
			RB_SET_BLACK(p);
			rotate_left(p, dpn);
			n = *dpn;
			break;
		}
		else {
			s = p->left; /* n == parent->right */
			if (RB_IS_RED(s)) {
				/* Case 1 - right rotate at parent */
				x = s->right;
				RB_SET_RED(p);
				RB_SET_BLACK(s);
				rotate_right(p, dpn);
				s = x;
			}
			y = s->left;
			if (!y || RB_IS_BLACK(y)) {
				x = s->right;
				if (!x || RB_IS_BLACK(x)) {
					/* Case 2 - sibling color flip */
					RB_SET_RED(s);
					if (RB_IS_RED(p)) /* Case 2-2 */
						RB_SET_BLACK(p);
					else { /* Case 2-1 */
						n = p;
						p = RB_PARENT(n);
						if (p)      continue;
					}
					break;
				}
				/* Case 3 - left rotate at sibling */
				RB_SET_RED(s);
				RB_SET_BLACK(x);
				rotate_left(s, dpn);
				y = s;
				s = x;
			}
			/* Case 4 - right rotate at parent + color flips */
			x = s->right;
			RB_SET_BLACK(y);
			RB_SET_COLOR(s, p);
			RB_SET_BLACK(p);
			rotate_right(p, dpn);
			n = *dpn;
			break;
		}
	}
	if (n)      RB_SET_BLACK(n);
}
void __erase_data_change_node(RB_NODE ** dpn, RB_NODE * delNode, RB_NODE * replace)
{
	if (RB_PARENT(delNode) == NULL)						*dpn = replace; /* If it's true, The delNode is the root node. */
	else if (RB_PARENT(delNode)->left == delNode)   RB_PARENT(delNode)->left = replace;
	else																	RB_PARENT(delNode)->right = replace;

	if (replace)      RB_SET_PARENT(replace, RB_PARENT(delNode));
}
void __erase_data(RB_NODE * delNode, RB_NODE ** dpn)
{
	RB_NODE *left, *replace, *n, *p = RB_PARENT(delNode);
	int color = RB_COLOR(delNode);
	if (!delNode->left) {
		n = delNode->right;
		__erase_data_change_node(dpn, delNode, n);
	}
	else if (!delNode->right) {
		n = delNode->left;
		__erase_data_change_node(dpn, delNode, n);
	}
	else {
		replace = delNode->right;
		while ((left = replace->left) != NULL)		replace = left;
		color = RB_COLOR(replace);
		n = replace->right;
		p = RB_PARENT(replace);
		if (p == delNode) /* if p and delNode are the same, it won't need to link between replace and delNode. */
			p = replace;
		else { /* Link replace->right to delNode->right. */
			__erase_data_change_node(dpn, replace, replace->right);
			replace->right = delNode->right;
			RB_SET_PARENT(replace->right, replace);
		}
		__erase_data_change_node(dpn, delNode, replace);
		replace->left = delNode->left;
		RB_SET_PARENT(replace->left, replace);
		RB_SET_COLOR(replace, delNode);
	}
	if (color == RB_BLACK)		__erase_data_color(n, p, dpn);
}
int erase_data(RB_NODE ** dpn, DATA rbdata)
{
	RB_NODE ** root = dpn;
	RB_NODE * delNode = NULL;
	RB_DATA * s;
	while (*dpn) {
		delNode = *dpn;
		s = RB_ENTRY_ADDR(delNode, RB_DATA, tree);
		if (s->rbdata == rbdata)       break;
		else if (s->rbdata > rbdata)	dpn = &(*dpn)->left;
		else									dpn = &(*dpn)->right;
	}
	if (*dpn == NULL)      return -1; /*This case can't find a data in storage.*/
	__erase_data(delNode, root);
	free(s);
	return 1;
}
void rotate_left(RB_NODE * pn, RB_NODE **dpn)
{
	RB_NODE * right = pn->right;
	RB_NODE * parent = RB_PARENT(pn);
	if ((pn->right = right->left))   RB_SET_PARENT(right->left, pn);
	right->left = pn;
	RB_SET_PARENT(right, parent);
	if (parent) {
		if (parent->left == pn)     parent->left = right;
		else                        parent->right = right;
	}
	else							*dpn = right;
	RB_SET_PARENT(pn, right);
}
void rotate_right(RB_NODE * pn, RB_NODE **dpn)
{
	RB_NODE * left = pn->left;
	RB_NODE * parent = RB_PARENT(pn);
	if ((pn->left = left->right))   RB_SET_PARENT(left->right, pn);
	left->right = pn;
	RB_SET_PARENT(left, parent);
	if (parent) {
		if (parent->left == pn)     parent->left = left;
		else						parent->right = left;
	}
	else                     *dpn = left;
	RB_SET_PARENT(pn, left);
}
void __insert_color(RB_NODE * npn, RB_NODE **dpn)
{
	RB_NODE *parent, *gparent, *uncle, *temp;
	while ((parent = RB_PARENT(npn)) && RB_IS_RED(parent)) {
		gparent = RB_PARENT(parent);
		if (gparent->left == parent) {
			uncle = gparent->right;
			if (uncle && RB_IS_RED(uncle)) {
				RB_SET_BLACK(parent);
				RB_SET_BLACK(uncle);
				RB_SET_RED(gparent);
				npn = gparent;
				continue;
			}

			if (parent->right == npn) /* if this is true, the tree must be LR tree. */ {
				rotate_left(parent, dpn);
				temp = parent;
				parent = npn;
				npn = temp;
			}
			RB_SET_BLACK(parent);
			RB_SET_RED(gparent);
			rotate_right(gparent, dpn);
		}
		else {
			uncle = gparent->left;
			if (uncle && RB_IS_RED(uncle))
			{
				RB_SET_BLACK(parent);
				RB_SET_BLACK(uncle);
				RB_SET_RED(gparent);
				npn = gparent;
				continue;
			}
			if (parent->left == npn) /* if this is true, the tree must be RL tree. */ {
				rotate_right(parent, dpn);
				temp = parent;
				parent = npn;
				npn = temp;
			}
			RB_SET_BLACK(parent);
			RB_SET_RED(gparent);
			rotate_left(gparent, dpn);
		}
	}
	RB_SET_BLACK(*dpn);
}
void __insert_link(RB_NODE * npn, RB_NODE * parent, RB_NODE **dpn)
{
	RB_SET_PARENT(npn, parent);
	npn->left = npn->right = 0;
	*dpn = npn;
}
int insert_data(RB_NODE ** dpn, RB_NODE * npn, DATA rbdata)
{
	RB_NODE ** root = dpn;
	RB_NODE * parent = NULL;
	RB_DATA * s;
	RB_SET_RED(npn);
	while (*dpn) {
		parent = *dpn;
		s = RB_ENTRY_ADDR(parent, RB_DATA, tree);
		if (s->rbdata == rbdata)			return -1;
		else if (s->rbdata > rbdata)		dpn = &(*dpn)->left;
		else										dpn = &(*dpn)->right;
	}
	__insert_link(npn, parent, dpn);
	__insert_color(npn, root);
	return 1;
}


void MoveLine(HDC hdc, int sX, int sY, int eX, int eY) { MoveToEx(hdc, sX, sY, 0);		LineTo(hdc, eX, eY); }
void InitialInfo(DrawInfo * pDrawInfo)
{
	static BOOL flag_initial = TRUE;
	if (flag_initial) { /* This part runs only one time. */
		pDrawInfo->root = NULL;
		pDrawInfo->node.size_node = INITIAL_NODE_SIZE;
		flag_initial = FALSE;
		pDrawInfo->node.dX = pDrawInfo->node.size_node;
		pDrawInfo->node.dY = pDrawInfo->node.size_node + (pDrawInfo->node.size_node / 5);
	}

	pDrawInfo->b_flag_eidt_input = FALSE;
	pDrawInfo->node.cX = NEW_NODE_POS_X;
	pDrawInfo->node.cY = NEW_NODE_POS_Y;
	if (pDrawInfo->root != NULL) {
		RB_DATA * s = RB_ENTRY_ADDR(pDrawInfo->root, RB_DATA, tree);
		pDrawInfo->node.nX = s->cX - (pDrawInfo->node.size_node + pDrawInfo->node.size_node / 5);
		pDrawInfo->node.nY = s->cY;
	}
	else {
		pDrawInfo->node.nX = ENTRY_NODE_POS_X - (pDrawInfo->node.size_node + pDrawInfo->node.size_node / 5);
		pDrawInfo->node.nY = ENTRY_NODE_POS_Y;
		pDrawInfo->node.cnt = 0;
	}
}
void EraseNode(DrawInfo * pDrawInfo)
{
	RECT rt;
	rt.left = pDrawInfo->node.cX - 5;
	rt.top = pDrawInfo->node.cY - 5;
	rt.right = pDrawInfo->node.cX + pDrawInfo->node.size_node;
	rt.bottom = pDrawInfo->node.cY + pDrawInfo->node.size_node;
	InvalidateRect(pDrawInfo->hWnd, &rt, TRUE);

}
void __drawboard_predict_pos_node(HDC hdc, int line_sX, int line_sY, int line_eX, int line_eY,
	int node_sX, int node_sY, int node_eX, int node_eY)
{
	HPEN MyPen, OldPen;
	MyPen = CreatePen(PS_DOT, 1, RGB(125, 125, 125));
	OldPen = (HPEN)SelectObject(hdc, MyPen);

	MoveLine(hdc, line_sX, line_sY, line_eX, line_eY);
	Ellipse(hdc, node_sX, node_sY, node_eX, node_eY);

	MoveLine(hdc, node_eX, line_eY, node_eX + ((node_eX - node_sX) / 5) - 4, line_eY);
	Ellipse(hdc, node_eX + ((node_eX - node_sX) / 5) - 2, node_sY - 2,
		node_eX + ((node_eX - node_sX) / 5) + (node_eX - node_sX) + 2, node_eY + 2);

	SelectObject(hdc, OldPen);
	DeleteObject(MyPen);
}
void __drawboard_draw_each_node(HDC hdc, TCHAR *  str, int cX, int cY, int size_node, int color)
{
	HBRUSH nBrush, oBrush;
	if (color == RB_RED)		nBrush = CreateSolidBrush(RGB(255, 10, 80));
	else								nBrush = CreateSolidBrush(RGB(30, 30, 30));
	oBrush = (HBRUSH)SelectObject(hdc, nBrush);

	SetTextColor(hdc, RGB(255, 255, 255));
	SetBkMode(hdc, TRANSPARENT);

	Ellipse(hdc, cX, cY, cX + size_node, cY + size_node);
	TextOut(hdc, cX + (size_node / 2) - (_tcslen(str) * 4), cY + ((size_node / 2) - 8), str, _tcslen(str));

	SelectObject(hdc, oBrush);
	DeleteObject(nBrush);
}
void __drawboard_new_node(DrawInfo * pDrawInfo, HDC hdc)
{
	int line_sX, line_sY, line_eX, line_eY, node_sX, node_sY, node_eX, node_eY;
	line_sX = pDrawInfo->node.cX + pDrawInfo->node.size_node;
	line_sY = pDrawInfo->node.cY + pDrawInfo->node.size_node / 2;
	line_eX = pDrawInfo->node.nX;
	line_eY = pDrawInfo->node.nY + pDrawInfo->node.size_node / 2;
	node_sX = pDrawInfo->node.nX;
	node_sY = pDrawInfo->node.nY;
	node_eX = pDrawInfo->node.nX + pDrawInfo->node.size_node;
	node_eY = pDrawInfo->node.nY + pDrawInfo->node.size_node;

	__drawboard_predict_pos_node(hdc, line_sX, line_sY, line_eX, line_eY, node_sX, node_sY, node_eX, node_eY);

	__drawboard_draw_each_node(hdc, pDrawInfo->str_edit_input,
		pDrawInfo->node.cX, pDrawInfo->node.cY, pDrawInfo->node.size_node, RB_RED);
}
void __drawboard_all_node(HDC hdc, RB_NODE * node, int size_node)
{
	TCHAR str[128] = { 0, };
	RB_DATA * d, *p;
	if (node == NULL)		return;

	d = RB_ENTRY_ADDR(node, RB_DATA, tree);
	wsprintf(str, _T("%d"), d->rbdata);

	__drawboard_all_node(hdc, node->left, size_node);
	__drawboard_draw_each_node(hdc, str, d->cX, d->cY, size_node, RB_COLOR(node));
	if (RB_PARENT(node)) {
		p = RB_ENTRY_ADDR(RB_PARENT(node), RB_DATA, tree);
		MoveLine(hdc, p->cX + (size_node / 2), p->cY + size_node, d->cX + (size_node / 2), d->cY);
	}
	__drawboard_all_node(hdc, node->right, size_node);
}
void DrawBoard(DrawInfo * pDrawInfo, HDC hdc)
{
	TCHAR str[128] = { 0, };
	wsprintf(str, _T("Input Data: "));												TextOut(hdc, 15, 10, str, _tcslen(str));
	wsprintf(str, _T("[※Node Count : %d]"), pDrawInfo->node.cnt);	TextOut(hdc, 15, 70, str, _tcslen(str));
	if (pDrawInfo->b_flag_eidt_input)		__drawboard_new_node(pDrawInfo, hdc);
	if (pDrawInfo->root)							__drawboard_all_node(hdc, pDrawInfo->root, pDrawInfo->node.size_node);
}
void __re_set_node_position(DrawInfo * pDrawInfo, RB_NODE * node, int * row, int * col)
{
	RB_DATA *d;
	if (node == NULL)		return;

	(*row)++;
	__re_set_node_position(pDrawInfo, node->left, row, col);
	d = RB_ENTRY_ADDR(node, RB_DATA, tree);
	d->cX = (pDrawInfo->node.dX * (*col)) + ENTRY_NODE_POS_X;
	d->cY = (pDrawInfo->node.dY * (*row)) + ENTRY_NODE_POS_Y;
	(*col)++;
	__re_set_node_position(pDrawInfo, node->right, row, col);
	(*row)--;
}
void ReSetNodePosition(DrawInfo * pDrawInfo)
{
	int row = -1, col = 0;

	__re_set_node_position(pDrawInfo, pDrawInfo->root, &row, &col);
}
void Insert_Node(DrawInfo * pDrawInfo)
{
	RB_DATA * d;
	d = (RB_DATA*)malloc(sizeof(RB_DATA));
	d->rbdata = _tstoi(pDrawInfo->str_edit_input);
	if (insert_data(&pDrawInfo->root, &(d->tree), d->rbdata) == -1) {
		free(d);
		return;
	}
	ReSetNodePosition(pDrawInfo);
	(pDrawInfo->node.cnt)++;
}
void Erase_Node(DrawInfo * pDrawInfo)
{
	if (erase_data(&pDrawInfo->root, _tstoi(pDrawInfo->str_edit_input)) == -1)	return;
	ReSetNodePosition(pDrawInfo);
	(pDrawInfo->node.cnt)--;
}