#include "MoveManager.h"



move_manager::move_manager(const LPVOID param)
	: hook_(param)
{
}


move_manager::~move_manager()
{
}

void move_manager::move(const HWND window, const int x, const int y)
{
	RECT* rect = new RECT();
	GetWindowRect(window, rect);
	const int width = rect->right - rect->left;
	const int height = rect->bottom - rect->top;

	MoveWindow(window, x, y, width, height, true);
}
