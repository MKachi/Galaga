#include "Enemy.h"
#include "../Config.h"

Enemy::Enemy(Scene* scene, Vector2 position, Direction direction)
	: _sprite(nullptr)
	, _position(position)
	, _direction(direction)
	, _state(EnemyState::Idle)
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
		_sprite->setPosition(Vector2(SCREEN_WIDTH, SCREEN_HEIGHT + 35));
		_sprite->setActive(true);
		break;
	case EnemyState::Idle:
		break;
	default:
		break;
	}
}

void Enemy::idleAction(Timer& timer)
{
	if (_direction == Direction::Left)
	{
		if (_position.x - 35 > _sprite->getPosition().x)
		{
			_direction = Direction::Right;
			return;
		}
		_sprite->setPosition(Vector2(
			_sprite->getPosition().x - 30.0f * timer.getDeltaTime(),
			_sprite->getPosition().y));
	}
	else
	{
		if (_position.x + 35 < _sprite->getPosition().x)
		{
			_direction = Direction::Left;
			return;
		}
		_sprite->setPosition(Vector2(
			_sprite->getPosition().x + 30.0f * timer.getDeltaTime(),
			_sprite->getPosition().y));
	}
}

void Enemy::spawnAction(Timer& timer)
{
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