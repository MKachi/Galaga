#include "GameScene.h"

void GameScene::init()
{
	sprite = Sprite::create("Player");
	this->addObject(sprite);
}

void GameScene::update()
{
    if (Input::isKeyState(KeyCode::Left))
    {
        printf("Left\n");
    }
}
