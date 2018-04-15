#include "GameScene.h"
#include "Resources.h"
#include "../Config.h"
#include "../framework/MathFunc.h"

GameScene::GameScene()
{	}

GameScene::~GameScene()
{
	SAFE_DELETE(_scheduler);
	for (int i = 0; i < EnemyPoolSize; ++i)
	{
		SAFE_DELETE(enemy[i]);
	}

	for (int i = 0; i < BulletSize; ++i)
	{
		SAFE_DELETE(bullet[i]);
	}
}

void GameScene::init()
{
	player = Sprite::create(ResPlayer);
	player->setPosition(Vector2(SCREEN_WIDTH / 2, 0.0f));
	player->setDepth(-1);
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

	fireCount = 0.0f;
	for (int i = 0; i < BulletSize; ++i)
	{
		bullet[i] = new Bullet(this);
	}

	_scheduler = new Scheduler();
	_scheduler->addSchedule(scheduleOnce(GameScene::firstSpawn, 3.0f));
}

void GameScene::update(Timer& timer)
{
	_scheduler->update(timer.getDeltaTime());
	fireCount += timer.getDeltaTime();
	for (int i = 0; i < EnemyPoolSize; ++i)
	{
		enemy[i]->update(timer);
	}

	for (int i = 0; i < BulletSize; ++i)
	{
		bullet[i]->update(timer);
	}

	inputUpdate(timer.getDeltaTime());
	physicsUpdate();
}

void GameScene::inputUpdate(float dt)
{
	Vector2 playerPos = player->getPosition();
	if (Input::isKeyState(KeyCode::Up))
	{
		playerPos.y = clamp(playerPos.y + playerSpeed * dt, 0.0f, SCREEN_HEIGHT - 60.0f);
	}

	if (Input::isKeyState(KeyCode::Down))
	{
		playerPos.y = clamp(playerPos.y - playerSpeed * dt, 0.0f, SCREEN_HEIGHT - 60.0f);
	}

	if (Input::isKeyState(KeyCode::Left))
	{
		playerPos.x = clamp(playerPos.x - playerSpeed * dt, 0.0f, SCREEN_WIDTH - 60.0f);
	}

	if (Input::isKeyState(KeyCode::Right))
	{
		playerPos.x = clamp(playerPos.x + playerSpeed * dt, 0.0f, SCREEN_WIDTH - 60.0f);
	}

	if (Input::isKeyState(KeyCode::Space))
	{
		if (fireCount >= fireDelay)
		{
			fireCount = 0.0f;
			for (int i = 0; i < BulletSize; ++i)
			{
				if (!bullet[i]->isActive())
				{
					bullet[i]->spawn(Vector2(player->getPosition().x + 23, player->getPosition().y + 60));
					break;
				}
			}
		}
	}

	player->setPosition(playerPos);
}

void GameScene::physicsUpdate()
{
	for (int i = 0; i < BulletSize; ++i)
	{
		if (bullet[i]->isActive())
		{
			for (int j = 0; j < EnemyPoolSize; ++j)
			{
				if (enemy[j]->getState() == EnemyState::Idle)
				{
					Rect enemyRect = enemy[j]->getRect();
					if (enemyRect.intersectRect(bullet[i]->getRect()))
					{
						bullet[i]->setActive(false);
						enemy[j]->setState(EnemyState::Die);
						return;
					}
				}
			}
		}
	}
}

// schedule func
void GameScene::firstSpawn(float dt)
{
	for (int i = 0; i < EnemyPoolSize; ++i)
	{
		enemy[i]->setState(EnemyState::SpawnAction);
	}
}
