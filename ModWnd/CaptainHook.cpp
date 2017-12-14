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
			if (!GetCursorPos(&point))continue;
			const HWND window = WindowFromPoint(point);
			if (window)
			{
				while (is_down())
				{
					move_wnd(window, point.x, point.y);
					if (!GetCursorPos(&point))break;
				}
			}
		}
		Sleep(1);
	}
}
