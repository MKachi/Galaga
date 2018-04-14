#pragma once

#include "../framework/Scene.h"
#include "../framework/Sprite.h"
#include "../framework/Input.h"

enum : uint { EnemyPoolSize = 30 };

class GameScene final
	: public Scene
{
	CREATE_SCENE(GameScene);
private:
	Sprite* player;
	Sprite* enemy[EnemyPoolSize];

};
