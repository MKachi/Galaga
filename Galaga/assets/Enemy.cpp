#include "Enemy.h"
#include "../Config.h"
#include "../framework/Random.h"

Enemy::Enemy(Scene* scene, Vector2 position, Direction direction)
	: _sprite(nullptr)
	, _position(position)
	, _movePosition(position)
	, _direction(direction)
	, _state(EnemyState::None)
{
	_sprite = Sprite::create("Enemy");
	_sprite->setActive(false);
	scene->addObject(_sprite);

	_rect.SetRect(
		_sprite->getPosition().x, _sprite->getPosition().y
		, 35.0f, 35.0f);

	_scheduler = new Scheduler();
}

Enemy::~Enemy()
{	
	SAFE_DELETE(_scheduler);
}

void Enemy::setState(EnemyState state)
{
	_state = state;
	float x;
	switch (state)
	{
	case EnemyState::SpawnAction:
		_sprite->setPosition(Vector2(random(0, SCREEN_WIDTH - 35), SCREEN_HEIGHT + 35));
		_sprite->setActive(true);
		_scheduler->addSchedule(scheduleOnce(Enemy::nextAction, 0.7f));
		return;
	case EnemyState::Idle:
		_sprite->setPosition(_position);
		return;
	case EnemyState::Die:
		_sprite->setActive(false);
		_scheduler->addSchedule(scheduleOnce(Enemy::respawn, 2.0f));
		return;
	default:
		return;
	}
}

void Enemy::respawn(float dt)
{
	setState(EnemyState::SpawnAction);
}

void Enemy::idleAction(Timer& timer)
{
	if (_direction == Direction::Left)
	{
		if (_position.x - 35 > _movePosition.x)
		{
			_direction = Direction::Right;
			return;
		}
		_movePosition.x -= 30.0f * timer.getDeltaTime();
	}
	else
	{
		if (_position.x + 35 < _movePosition.x)
		{
			_direction = Direction::Left;
			return;
		}
		_movePosition.x += 30.0f * timer.getDeltaTime();
	}
}

void Enemy::nextAction(float dt)
{
	setState(EnemyState::Idle);
}

void Enemy::spawnAction(Timer& timer)
{
	Vector2 position = _sprite->getPosition();
	position.x = lerp(position.x, _position.x, 7.0f * timer.getDeltaTime());
	position.y = lerp(position.y, _position.y, 7.0f * timer.getDeltaTime());
	_sprite->setPosition(position);
}

void Enemy::update(Timer& timer)
{
	_scheduler->update(timer.getDeltaTime());

	switch (_state)
	{
	case EnemyState::SpawnAction:
		spawnAction(timer);
		break;
	case EnemyState::Die:
		idleAction(timer);
		break;
	case EnemyState::Idle:
		idleAction(timer);
		_sprite->setPosition(_movePosition);
		break;
	default:
		break;
	}
	_rect.SetRect(
		_sprite->getPosition().x, _sprite->getPosition().y
		, 35.0f, 35.0f);
}