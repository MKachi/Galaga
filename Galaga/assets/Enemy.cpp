#include "Enemy.h"
#include "../Config.h"
#include "../framework/Random.h"

Enemy::Enemy(Scene* scene, Vector2 position, Direction direction)
	: _sprite(nullptr)
	, _position(position)
	, _direction(direction)
	, _state(EnemyState::Die)
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
	float x;
	switch (state)
	{
	case EnemyState::SpawnAction:
		x = random(0, SCREEN_WIDTH - 35);
		_spawnBigX = x > _position.x;

		_sprite->setPosition(Vector2(x, SCREEN_HEIGHT + 35));
		_sprite->setActive(true);
		return;
	case EnemyState::Idle:
		_sprite->setPosition(_position);
		return;
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
	Vector2 position = _sprite->getPosition();
	if (_spawnBigX)
	{
		if (position.x <= _position.x &&
			position.y <= _position.y)
		{
			setState(EnemyState::Idle);
		}
	}
	else
	{
		if (position.x >= _position.x &&
			position.y <= _position.y)
		{
			setState(EnemyState::Idle);
		}
	}
	position.x = lerp(position.x, _position.x, 7.0f * timer.getDeltaTime());
	position.y = lerp(position.y, _position.y, 7.0f * timer.getDeltaTime());
	_sprite->setPosition(position);
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