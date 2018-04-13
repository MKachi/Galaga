#pragma once

#include "OpenAL.h"

class AudioListener
{
private:
	ALCdevice*	_device;
	ALCcontext* _context;

public:
	AudioListener();
	~AudioListener();

	bool init();

};
