#include <vector>
#include "Scheduler.h"

Schedule::Schedule(const std::function<void(float)>& function, const string& key, float time, bool once, Scheduler* scheduler)
	: _function(function)
	, _time(time)
	, _counter(0.0f)
	, _once(once)
	, _key(key)
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
{	
	for (int i = 0; i < _schedules.size(); ++i)
	{
		SAFE_DELETE(_schedules[i]);
	}
}

void Scheduler::addSchedule(const std::function<void(float)>& function, const string& key, float time, bool once)
{
	_schedules.push_back(new Schedule(function, key, time, once, this));
}

void Scheduler::removeSchedule(const string& key)
{
	std::vector<Schedule*>::iterator iter = _schedules.begin();
	for (; iter != _schedules.end(); ++iter)
	{
		if ((*iter)->getKey() == key)
		{
			break;
		}
	}
	
	if (iter != _schedules.end())
	{
		_schedules.erase(iter);
	}
}

void Scheduler::update(float dt)
{
	for (int i = 0; i < _schedules.size(); ++i)
	{
		_schedules[i]->update(dt);
	}
}