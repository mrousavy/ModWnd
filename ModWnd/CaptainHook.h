#pragma once
#include <windows.h>

/// \brief A Hook helper for hooking to modifier 
/// key down & mouse move on a window
class captain_hook
{
private:
	HHOOK h_keyboard_hook_;
public:
	explicit captain_hook(const LPVOID lp_parm);
	~captain_hook();
};

