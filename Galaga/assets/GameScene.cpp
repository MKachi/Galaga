#include "GameScene.h"

void GameScene::init()
{
	sprite = Sprite::create("Player");
	this->addObject(sprite);
}

void GameScene::update(Timer& timer)
{
	system("cls");
	printf("%f\n", 1 / timer.getDeltaTime());
    if (Input::isKeyState(KeyCode::Left))
    {
        printf("Left\n");
    }
}
