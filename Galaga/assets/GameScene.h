#pragma once

#include "../framework/Scene.h"
#include "../framework/Input.h"
#include "Enemy.h"
#include "Bullet.h"

enum : uint { EnemyPoolSize = 28, BulletSize = 100, };
const float fireDelay = 0.3f;

class GameScene final
	: public Scene
{
	CREATE_SCENE(GameScene);
private:
	Sprite* player;
	Enemy*	enemy[EnemyPoolSize];

	Bullet* bullet[BulletSize];
	float	fireCount;

public:
	GameScene();
	virtual ~GameScene();

};
