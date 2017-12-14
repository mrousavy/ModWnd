#include "CaptainHook.h"
#include <iostream>
#include <Windows.h>

captain_hook::captain_hook(const int key)
	: hotkey(key)
{
	instance_ = this;
}

captain_hook::~captain_hook()
{
	instance_ = nullptr;
	m_hook_ = nullptr;
	UnhookWindowsHookEx(m_hook_);
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

void captain_hook::register_m()
{
	// If nothing has hooked yet, hook mouse
	SetWindowsHookEx(WH_MOUSE_LL, mouse_callback, GetModuleHandle(nullptr), 0);
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

bool captain_hook::is_down() const
{
	const bool hk = GetKeyState(hotkey) & active_flg_;
	const bool mb = GetKeyState(VK_LBUTTON) & 0x100;
	return hk && mb;
}


#pragma region Mouse
HHOOK captain_hook::m_hook_;
captain_hook* captain_hook::instance_;
LRESULT CALLBACK captain_hook::mouse_callback(const int n_code, const WPARAM w_param, const LPARAM l_param) 
{
	if (n_code == HC_ACTION)
	{
		MSLLHOOKSTRUCT &msll = *(reinterpret_cast<MSLLHOOKSTRUCT*>(l_param));

		if (w_param == WM_LBUTTONDOWN)	// Is it a mouse click?
		{
			return -1;
			if (instance_->is_down())
			{
				return -1;	// Ignore mouse click
			}
		}
	}

	return CallNextHookEx(m_hook_, n_code, w_param, l_param); // Pass to next handlers
}
#pragma endregion 
