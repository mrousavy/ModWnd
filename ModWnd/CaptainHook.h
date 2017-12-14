#pragma once
#include "MoveManager.h"

class captain_hook
{
public:
	/// \brief Initialize a new instance of the Captain Hook class
	/// \param key The hotkey to bind the events on
	explicit captain_hook(int key);
	/// \brief Delete this instance and cleanup
	~captain_hook();
	/// \brief Start the hook loop (blocking forever)
	void start();
	/// \brief Stop the hook loop
	void stop();
	/// \brief Register mouse hook
	static void register_m();
	/// \brief The Hotkey to bind to
	int hotkey;
private:
	/// \brief The loop for button & mouse checking
	void loop() const;
	/// \brief Flag indicating the loop should still run
	bool run_flag_ = true;
	/// \brief The GetKeyState active AND checker
	int active_flg_ = 0x8000;
	/// \brief Is the hotkey held down
	bool is_down() const;

	/// \brief The mouse hook
	static HHOOK m_hook_;
	/// \brief An instance of this class
	static captain_hook* instance_;
	/// \brief Low level mouse click callback
	static LRESULT CALLBACK mouse_callback(int n_code, WPARAM w_param, LPARAM l_param);
};

