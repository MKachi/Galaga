#pragma once

#include "../framework/CacheManager.h"

#define ResPlayer		"Player"
#define ResEnemy		"Enemy"
#define ResBullet		"Bullet"

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