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
			if (!GetCursorPos(&point)) continue;	// Mouse position
			const HWND window = WindowFromPoint(point);	// Get window handle from mouse
			if (window)
			{
				EnableWindow(window, false); // Disable click passthrough
				while (is_down())	// Loop on held down
				{
					move_wnd(window, point.x, point.y);	// Move window to ...
					if (!GetCursorPos(&point)) break;	// Update cursor position
				}
				EnableWindow(window, true);	// Enable click passthrough
			}
		}
		Sleep(1);
	}
}

void captain_hook::click() const
{
	INPUT input;
	input.type = INPUT_MOUSE;
	input.mi.dx = 0;
	input.mi.dy = 0;
	input.mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE | MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP);
	input.mi.mouseData = 0;
	input.mi.dwExtraInfo = NULL;
	input.mi.time = 0;
	SendInput(1, &input, sizeof(INPUT));
}

bool captain_hook::is_down() const
{
	const bool hk = GetKeyState(hotkey) & active_flg_;
	const bool mb = GetKeyState(VK_LBUTTON) & 0x100;
	return hk && mb;
}
