#include "GameScene.h"

void GameScene::init()
{
	player = Sprite::create(Player);
	this->addObject(player);

	for (int i = 0; i < EnemyPoolSize; ++i)
	{
		enemy[i] = Sprite::create(Enemy);
		enemy[i]->setActive(false);
		this->addObject(enemy[i]);
	}
}

void GameScene::update(Timer& timer)
{
	Vector2 playerPos = player->getPosition();
	if (Input::isKeyState(KeyCode::Up))
	{
		playerPos.y += 100.0f * timer.getDeltaTime();
	}
	
	if (Input::isKeyState(KeyCode::Down))
	{
		playerPos.y -= 100.0f * timer.getDeltaTime();
	}

	if (Input::isKeyState(KeyCode::Left))
	{
		playerPos.x -= 100.0f * timer.getDeltaTime();
	}

	if (Input::isKeyState(KeyCode::Right))
	{
		playerPos.x += 100.0f * timer.getDeltaTime();
	}

	player->setPosition(playerPos);
}