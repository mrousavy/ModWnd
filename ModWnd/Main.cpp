#include "MoveManager.h"
#include "CaptainHook.h"
#include <iostream>
#include <Windows.h>


int main(const int argc, char** argv)
{
	int hotkey = VK_MENU;
	if(argc > 0)
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
	hook.start();

	getchar();
	return 0;
}
