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
	hook.start();	//TODO: BLOCKING
	hook.register_m();
	
	MSG msg;
	// Create a Message Loop for the low level mouse hook
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		// Dispatch & Forward current message
		DispatchMessage(&msg);
	}



	return 0;
}
