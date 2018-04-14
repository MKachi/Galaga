#pragma once

#include "../framework/Scene.h"
#include "../framework/Input.h"
#include "Enemy.h"
#include "Bullet.h"

enum : uint { EnemyPoolSize = 28, BulletSize = 100, };
const float fireDelay = 0.3f;
const float playerSpeed = 200.0f;

class GameScene final
	: public Scene
{
	CREATE_SCENE(GameScene);
private:
	Sprite* player;
	Enemy*	enemy[EnemyPoolSize];

	Bullet* bullet[BulletSize];
	float	fireCount;

	Scheduler* _scheduler;

public:
	GameScene();
	virtual ~GameScene();

	void firstSpawn(float dt);

};
