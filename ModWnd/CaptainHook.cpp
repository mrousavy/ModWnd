#include "CaptainHook.h"
#include <iostream>
#include <Windows.h>

captain_hook::captain_hook(const int key)
	: hotkey(key)
{
}

captain_hook::~captain_hook()
{
	stop();
}

void captain_hook::start()
{
	run_flag_ = true;
	loop();
}

void captain_hook::stop()
{
	run_flag_ = false;
}

void captain_hook::loop() const
{
	// Loop while run flag is there
	while (run_flag_)
	{
		// Check if hotkey is held down
		if (is_down())
		{
			POINT point;
			if (!GetCursorPos(&point))continue;	// Mouse position
			const HWND window = WindowFromPoint(point);	// Get window handle from mouse
			if (window)
			{
				while (is_down())	// Loop on held down
				{
					move_wnd(window, point.x, point.y);	// Move window to ...
					if (!GetCursorPos(&point))break;	// Update cursor position
				}
			}
		}
		Sleep(1);
	}
}
