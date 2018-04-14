#include "GameScene.h"
#include "Resources.h"
#include "../Config.h"

GameScene::GameScene()
{	}

GameScene::~GameScene()
{
	for (int i = 0; i < EnemyPoolSize; ++i)
	{
		SAFE_DELETE(enemy[i]);
	}
}

void GameScene::init()
{
	player = Sprite::create(ResPlayer);
	player->setPosition(Vector2(SCREEN_WIDTH / 2, 0.0f));
	this->addObject(player);

	int index = 0;
	Vector2 position((SCREEN_WIDTH / 2) - (35 * 4), SCREEN_HEIGHT - 50);
	Direction direction = Direction::Left;

	for (int y = 0; y < 4; ++y)
	{
		for (int x = 0; x < 7; ++x)
		{
			enemy[index] = new Enemy(this, position, direction);
			position.x += 40;
			++index;
		}

		if (direction == Direction::Left)
		{
			direction = Direction::Right;
		}
		else
		{
			direction = Direction::Left;
		}
		position.x = (SCREEN_WIDTH / 2) - (35 * 4);
		position.y -= 50;
	}
}

void GameScene::update(Timer& timer)
{
	for (int i = 0; i < EnemyPoolSize; ++i)
	{
		enemy[i]->update(timer);
	}

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

	if (Input::isKeyState(KeyCode::Space))
	{
		for (int i = 0; i < EnemyPoolSize; ++i)
		{
			if (enemy[i]->getState() == EnemyState::Die)
			{
				enemy[i]->setState(EnemyState::SpawnAction);
			}
		}
	}

	player->setPosition(playerPos);
}