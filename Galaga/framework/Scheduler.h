#pragma once

#include "Rule.h"
#include <functional>
#include <vector>

#define schedule(_FUNC_, _TIME_) std::bind(&_FUNC_, this, std::placeholders::_1), #_FUNC_, _TIME_
#define scheduleOnce(_FUNC_, _TIME_) std::bind(&_FUNC_, this, std::placeholders::_1), #_FUNC_, _TIME_, true

class Scheduler;
class Schedule
{
private:
	std::function<void(float)> _function;
	Scheduler*	_scheduler;
	string		_key;
	float		_time;
	float		_counter;
	bool		_once;

public:
	Schedule() = default;
	Schedule(const std::function<void(float)>& function, const string& key, float time, bool once, Scheduler* scheduler);
	~Schedule();

	string getKey() { return _key; }

	void update(float dt);

};

class Scheduler
{
private:
	std::vector<Schedule*> _schedules;

public:
	Scheduler();
	~Scheduler();

	void addSchedule(const std::function<void(float)>& function, const string& key, float time, bool once = false);
	void removeSchedule(const string& key);
	void update(float dt);

};