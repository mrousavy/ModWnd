#include "CaptainHook.h"
#include <iostream>
#include <Windows.h>

CaptainHook::CaptainHook(int key)
	: hotkey(key)
{
}

CaptainHook::~CaptainHook()
{
}

void CaptainHook::start()
{
	loop();
}

void CaptainHook::loop()
{
	while (true)
	{
		if (GetKeyState(hotkey) & 0x8000)
		{

		}
		Sleep(1);
	}
}
