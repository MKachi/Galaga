#pragma once

#if _WINDOWS
#include <al.h>
#include <alc.h>
#else
#include <OpenAL/al.h>
#include <OpenAL/alc.h>
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
