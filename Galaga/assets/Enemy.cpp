#include "Enemy.h"
#include "../Config.h"

void Enemy::spawnAction(Timer & timer)
{
}

void Enemy::idleAction(Timer & timer)
{
}

Enemy::Enemy(Scene* scene, Vector2 position)
	: _sprite(nullptr)
	, _position(position)
	, _state(EnemyState::SpawnAction)
{
	_sprite = Sprite::create("Enemy");
	_sprite->setActive(false);
	scene->addObject(_sprite);
}

Enemy::~Enemy()
{	}

void Enemy::setState(EnemyState state)
{
	_state = state;
	switch (state)
	{
	case EnemyState::SpawnAction:
		_sprite->setPosition(Vector2(SCREEN_WIDTH, SCREEN_HEIGHT + 10));
		_sprite->setActive(true);
		break;
	case EnemyState::Idle:
		break;
	default:
		break;
	}
}

void Enemy::update(Timer& timer)
{
	switch (_state)
	{
	case EnemyState::SpawnAction:
		spawnAction(timer);
		break;
	case EnemyState::Idle:
		idleAction(timer);
		break;
	default:
		break;
	}
}