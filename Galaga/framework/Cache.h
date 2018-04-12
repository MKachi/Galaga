#pragma once

#include "Rule.h"

class Cache
{
protected:
	string	_key;
	int		_ref;

public:
	Cache();
	virtual ~Cache();

	void retain();
	void release();

	string getKey() { return _key; }

};