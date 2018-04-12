#pragma once

#include "../framework/Scene.h"
#include "../framework/Sprite.h"

class GameScene final
	: public Scene
{
	CREATE_SCENE(GameScene);
private:
	Sprite* sprite;

};