#include <vector>
#include "Scheduler.h"

Schedule::Schedule(const std::function<void(float)>& function, const string& key, float time, bool once, Scheduler* scheduler)
	: _function(function)
	, _time(time)
	, _counter(0.0f)
	, _once(once)
	, _scheduler(scheduler)
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
		if (_once)
		{
			_scheduler->removeSchedule(_key);
		}
	}
}

Scheduler::Scheduler()
{	}

Scheduler::~Scheduler()
{	}

void Scheduler::addSchedule(const std::function<void(float)>& function, const string& key, float time, bool once)
{
	_schdules.push_back(Schedule(function, key, time, once, this));
}

void Scheduler::removeSchedule(const string& key)
{
	auto iter = _schdules.begin();
	for (; iter != _schdules.end(); ++iter)
	{
		if ((*iter).getKey() == key)
		{
			break;
		}
	}
	_schdules.erase(iter);
}

void Scheduler::update(float dt)
{
	for (auto& schedule : _schdules)
	{
		schedule.update(dt);
	}
}