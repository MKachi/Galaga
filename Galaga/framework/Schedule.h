#pragma once

#include <functional>

class Schedule
{
private:
	std::function<void(float)> _function;
	float _time;
	float _counter;

public:
	Schedule(const std::function<void(float)>& function, float time);
	~Schedule();

	void update(float dt);

};

void addSchedule(const std::function<void(float)>& function, float time);
void removeSchedule(const std::function<void(float)>& function, float time);
void updateSchedules(float dt);