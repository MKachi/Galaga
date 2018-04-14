#pragma once

#include "../framework/Scene.h"
#include "../framework/Input.h"
#include "Enemy.h"

enum : uint { EnemyPoolSize = 28 };

class GameScene final
	: public Scene
{
	CREATE_SCENE(GameScene);
private:
	Sprite* player;
	Enemy* enemy[EnemyPoolSize];

public:
	GameScene();
	virtual ~GameScene();

};
