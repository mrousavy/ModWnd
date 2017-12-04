#include "CaptainHook.h"
#pragma comment( lib, "user32.lib" )

#include <iostream>
#include <windows.h>


captain_hook::captain_hook(const LPVOID lp_parm)
{
	HINSTANCE h_instance = GetModuleHandle(nullptr);
	if (!h_instance) h_instance = LoadLibrary(static_cast<LPCSTR>(lp_parm));
	if (!h_instance) throw std::exception("h_instance library could not be loaded!");

	h_keyboard_hook_ = SetWindowsHookEx(WH_KEYBOARD_LL, static_cast<HOOKPROC>(keyboard_event), h_instance, NULL);
}


captain_hook::~captain_hook()
{
	UnhookWindowsHookEx(h_keyboard_hook_);
}
