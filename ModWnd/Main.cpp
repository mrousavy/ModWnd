#include "MoveManager.h"
#include "CaptainHook.h"
#include <iostream>
#include <Windows.h>


int main(int argc, char** argv)
{
	// Print Init Message
	std::cout << "Initializing ModWnd.." << std::endl;

	// Hide the Console Window
	//ShowWindow(GetConsoleWindow(), SW_HIDE);
	
	captain_hook hook(VK_MENU);
	hook.start();

	getchar();
	return 0;
}
