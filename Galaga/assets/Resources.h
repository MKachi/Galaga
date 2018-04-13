#pragma once

#include "../framework/CacheManager.h"

#define Player		"Player"
#define Enemy		"Enemy"

class Resources final
{
private:
	CacheManager* _manager;

public:
	Resources();
	Resources(const Resources&) = delete;
	Resources(Resources&&) = delete;
	~Resources();

	bool load();

};