#pragma once
#include <Windows.h>

#define DECLARE_MESSAGE_MAP() static MessageMap messageMap[];
#define BEGIN_MESSAGE_MAP(class_name) MessageMap class_name::messageMap[] = {
#define END_MESSAGE_MAP()			{0,NULL}};

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParma, LPARAM lParam);