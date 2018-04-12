#pragma once

#if _WINDOWS
#include <al.h>
#include <alc.h>
#else
#endif

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