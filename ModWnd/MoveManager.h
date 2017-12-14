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

	const int dx = x - rect.left;
	const int dy = y - rect.top;
	const int to_x = x + dx;
	const int to_y = y + dy;

	SetWindowPos(window, nullptr, to_x, to_y, 0, 0, SWP_NOOWNERZORDER | SWP_NOREDRAW | SWP_NOSIZE);
	//MoveWindow(window, to_x, to_y, width, height, true);
}
