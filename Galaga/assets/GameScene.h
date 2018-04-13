#pragma once

#include "Resources.h"
#include "../framework/Scene.h"
#include "../framework/Sprite.h"
#include "../framework/Input.h"

enum : uint { EnemyPoolSize = 100 };

class GameScene final
	: public Scene
{
	CREATE_SCENE(GameScene);
private:
	Sprite* player;
	Sprite* enemy[EnemyPoolSize];

};
