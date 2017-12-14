#pragma once
#include <Windows.h>

/// \brief Move the given Window (by handle) to the specified position
/// \param window A handle to the Window
/// \param x The X coordinate in pixels
/// \param y The Y coordinate in pixels
inline void move_wnd(const HWND window, const int x, const int y)
{
	RECT rect;
	GetWindowRect(window, &rect);

	const int to_x = x;//x + (x - rect.left);
	const int to_y = y;//y + (y - rect.top);

	SetWindowPos(window, nullptr, to_x, to_y, 0, 0, SWP_NOOWNERZORDER | SWP_NOREDRAW | SWP_NOSIZE);
	//MoveWindow(window, to_x, to_y, width, height, true);
}
