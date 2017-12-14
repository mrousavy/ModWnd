#pragma once

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
	/// \brief The Hotkey to bind to
	int hotkey;
private:
	/// \brief The loop for button & mouse checking
	void loop() const;
	/// \brief Flag indicating the loop should still run
	bool run_flag_ = true;
};

