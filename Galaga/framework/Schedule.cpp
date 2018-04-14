#include "Schedule.h"
#include <vector>

static std::vector<Schedule> _schdules;

Schedule::Schedule(const std::function<void(float)>& function, float time)
	: _function(function)
	, _time(time)
	, _counter(0.0f)
{	}

Schedule::~Schedule()
{	}

void Schedule::update(float dt)
{
	_counter += dt;
	if (_counter >= _time)
	{
		_counter = 0.0f;
		_function(dt);
	}
}

void addSchedule(const std::function<void(float)>& function, float time)
{
	_schdules.push_back(Schedule(function, time));
}

void removeSchedule(const std::function<void(float)>& function, float time)
{
	_schdules.erase(std::find(_schdules.begin(), _schdules.end(), Schedule(function, time)));
}

void updateSchedules(float dt)
{
	for (auto& schdule : _schdules)
	{
		schdule.update(dt);
	}
}