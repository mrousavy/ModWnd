#pragma once

class CaptainHook
{
public:
	/// \brief Initialize a new instance of the Captain Hook class
	CaptainHook();
	/// \brief Delete this instance and cleanup
	~CaptainHook();
	/// \brief The loop for button & mouse checking
	void loop();
};

