#pragma once

#include "../framework/CacheManager.h"

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