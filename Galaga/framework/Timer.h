#pragma once

#include "Rule.h"
#include <chrono>

class Timer final
{
private:
	std::chrono::steady_clock::time_point _currentTime;
	std::chrono::steady_clock::time_point _lastTime;
	float _deltaTime;
	float _timeScale;

public:
	Timer();
	~Timer();

	void tick();
	void setTimeScale(const float scale);
	float getTimeScale() const { return _timeScale; }
	float getDeltaTime() const { return _deltaTime * _timeScale; }
	float getUnscaledDeltaTime() const { return _deltaTime; }

};