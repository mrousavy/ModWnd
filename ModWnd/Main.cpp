#include "MoveManager.h"
#include "CaptainHook.h"
#include <iostream>
#include <Windows.h>
#include <thread>


int main(const int argc, char** argv)
{
	int hotkey = VK_MENU;
	if (argc > 0)
	{
		hotkey = atoi(argv[0]);
		if (hotkey > MAXINT || hotkey < 1)
			hotkey = VK_MENU;
	}

	// Print Init Message
	std::cout << "Initializing ModWnd.." << std::endl;

	// Hide the Console Window
	//ShowWindow(GetConsoleWindow(), SW_HIDE);

	captain_hook hook(hotkey);
	std::thread thread([&hook]()
	{
		// TODO: 
		SetPriorityClass(GetCurrentThread(), REALTIME_PRIORITY_CLASS);
		hook.register_m();
	});
	hook.start();

	return 0;
}
