#include "AudioListener.h"

AudioListener::AudioListener()
{	}

AudioListener::~AudioListener()
{
	if (_context != nullptr)
	{
		alcMakeContextCurrent(nullptr);
		alcDestroyContext(_context);
		_context = nullptr;
	}

	if (_device != nullptr)
	{
		alcCloseDevice(_device);
		_device = nullptr;
	}
}

bool AudioListener::init()
{
	_device = alcOpenDevice(nullptr);
	if (_device == nullptr)
	{
		return false;
	}

	_context = alcCreateContext(_device, nullptr);
	if (_context == nullptr)
	{
		return false;
	}

	alcMakeContextCurrent(_context);

	float position[] = { 0.0f, 0.0f, 0.0f };
	alListenerfv(AL_POSITION, position);

	return true;
}
