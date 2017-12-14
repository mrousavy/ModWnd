#pragma once
#include <Windows.h>

/// \brief Move the given Window (by handle) to the specified position
/// \param window A handle to the Window
/// \param mouse The X and Y coordinates of the Mouse cursor
inline void move_wnd(const HWND window, const POINT mouse)
{
	RECT rect;
	GetWindowRect(window, &rect);

	POINT client_point(mouse);
	ScreenToClient(window, &client_point);

	const int to_x = mouse.x;// +client_point.x;
	const int to_y = mouse.y;// +client_point.y;

	//SetWindowPos(window, nullptr, to_x, to_y, 0, 0, SWP_NOREDRAW | SWP_NOSIZE);
	MoveWindow(window, to_x, to_y, rect.right - rect.left, rect.bottom - rect.top, true);
}
