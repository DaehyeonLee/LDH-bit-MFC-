
// RB_testDoc.h: CRBtestDoc 클래스의 인터페이스
//


#pragma once

#include <tchar.h>
typedef int DATA;
typedef struct _rbtreenode {
	unsigned long rb_parent_color;
	struct _rbtreenode * left;
	struct _rbtreenode * right;
}RB_NODE;
typedef struct _rbdata {
	DATA rbdata;
	RB_NODE tree;
	int cX, cY; /* These variable muse be used by win api. */
}RB_DATA;

#define RB_RED											0
//red node

#define RB_BLACK										1
//black node

#define INPUT_LEN										10
//입력받는 숫자의 최대길이

#define RB_ENTRY_ADDR(n, type, member)	( (type*)((TCHAR*)(n) - ((unsigned long)&((type*)0)->member)) )
//use offset, check color

#define RB_PARENT(n)									( (RB_NODE*)(((n)->rb_parent_color) & ~3) )
//extraction parent

#define RB_COLOR(n)									( ((n)->rb_parent_color) & 1 )
//extraction parent color

#define RB_SET_PARENT(n, parent)				( (n)->rb_parent_color = ((RB_COLOR(n)) | ((unsigned long)parent)) )
//parent set(parent+color(low 2bit))

#define RB_SET_RED(n)								( ((n)->rb_parent_color) &= ~3 )


#define RB_SET_BLACK(n)							( ((n)->rb_parent_color) |= 1 )


#define RB_SET_COLOR(n, p)						( (n)->rb_parent_color = (((unsigned long)RB_PARENT(n)) | RB_COLOR(p)) )


#define RB_IS_RED(n)									( !(RB_COLOR(n)) )
//change red

#define RB_IS_BLACK(n)								( (RB_COLOR(n)) )
//change black

int erase_data(RB_NODE **, DATA);
//erase data

int insert_data(RB_NODE **, RB_NODE *, DATA);
//insert data

void rotate_left(RB_NODE *, RB_NODE **);
//rotate left

void rotate_right(RB_NODE *, RB_NODE **);
//rotatae right

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



class CRBtestDoc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CRBtestDoc() noexcept;
	DECLARE_DYNCREATE(CRBtestDoc)

// 특성입니다.
public:
// 작업입니다.
public:
	void __erase_data_color(RB_NODE * , RB_NODE * , RB_NODE **);
	void __erase_data_change_node(RB_NODE **, RB_NODE *, RB_NODE *);
	void __erase_data(RB_NODE *, RB_NODE **);
	int erase_data(RB_NODE **, DATA );
	void rotate_left(RB_NODE *, RB_NODE **);
	void rotate_right(RB_NODE *, RB_NODE **);
	void __insert_color(RB_NODE *, RB_NODE **);
	void __insert_link(RB_NODE *, RB_NODE *, RB_NODE **);
	int insert_data(RB_NODE ** , RB_NODE * , DATA );

	void MoveLine(HDC hdc, int sX, int sY, int eX, int eY);

	void InitialInfo(DrawInfo *);
	void EraseNode(DrawInfo *);
	void __drawboard_predict_pos_node(HDC, int, int, int, int, int, int, int, int);
	void __drawboard_draw_each_node(HDC, TCHAR *, int, int, int, int);
	void __drawboard_new_node(DrawInfo *, HDC);
	void __drawboard_all_node(HDC, RB_NODE *, int);
	void DrawBoard(DrawInfo *, HDC);
	void __re_set_node_position(DrawInfo *, RB_NODE *, int *, int *);
	void ReSetNodePosition(DrawInfo *);
	void Insert_Node(DrawInfo *);
	void Erase_Node(DrawInfo *);


	//void InitialInfo(DrawInfo *);
	//void DrawBoard(DrawInfo *, HDC);
	//void CRBtestDoc::MoveLine(HDC, int, int, int, int);
	//void EraseNode(DrawInfo *);
	//void Insert_Node(DrawInfo *);
	//void Erase_Node(DrawInfo *);
	

	//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CRBtestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
