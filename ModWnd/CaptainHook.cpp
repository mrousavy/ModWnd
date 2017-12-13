#include "CaptainHook.h"
#include <iostream>
#include <Windows.h>

CaptainHook::CaptainHook(int key)
	: hotkey(key)
{
}

CaptainHook::~CaptainHook()
{
	stop();
}

void CaptainHook::start()
{
	run_flag = true;
	loop();
}

void CaptainHook::stop()
{
	run_flag = false;
}

void CaptainHook::loop()
{
	while (run_flag)
	{
		if (GetKeyState(hotkey) & 0x8000)
		{

		}
		Sleep(1);
	}
}
