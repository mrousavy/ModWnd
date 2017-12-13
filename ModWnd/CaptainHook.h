#pragma once

class CaptainHook
{
public:
	/// \brief Initialize a new instance of the Captain Hook class
	/// \param key The hotkey to bind the events on
	CaptainHook(int key);
	/// \brief Delete this instance and cleanup
	~CaptainHook();
	/// \brief Start the hook loop (blocking forever)
	void start();
	/// \brief The Hotkey to bind to
	int hotkey;
private:
	/// \brief The loop for button & mouse checking
	void loop();
};

