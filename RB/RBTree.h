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
