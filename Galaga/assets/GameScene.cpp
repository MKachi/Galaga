#include "GameScene.h"
#include "Resources.h"
#include "../Config.h"

void GameScene::init()
{
	player = Sprite::create(Player);
	player->setPosition(Vector2(SCREEN_WIDTH / 2, 0.0f));
	this->addObject(player);

	int index = 0;
	Vector2 position((SCREEN_WIDTH / 2) - (35 * 4), SCREEN_HEIGHT - 50);

	for (int y = 0; y < 4; ++y)
	{
		for (int x = 0; x < 7; ++x)
		{
			enemy[index] = Sprite::create(Enemy);
			enemy[index]->setPosition(position);
			this->addObject(enemy[index]);

			position.x += 40;
			++index;
		}
		position.x = (SCREEN_WIDTH / 2) - (35 * 4);
		position.y -= 50;
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