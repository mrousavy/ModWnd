#include "CaptainHook.h"
#include <iostream>
#include <Windows.h>

captain_hook::captain_hook(int key)
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
	while (run_flag_)
	{
		if (GetKeyState(hotkey) & 0x8000)
		{

		}
		Sleep(1);
	}
}
