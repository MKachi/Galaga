#pragma once

#include "Rule.h"

class Cache
{
private:
	int _ref;

public:
	Cache();
	virtual ~Cache();

	void retain();
	void release();

};