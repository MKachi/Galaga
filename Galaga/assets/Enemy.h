#pragma once

#include "../framework/Sprite.h"
#include "../framework/Scene.h"

enum class EnemyState
{
	SpawnAction,
	Idle,
};

enum class Direction 
{ 
	Left, Right 
};

class Enemy
{
private:
	Sprite*		_sprite;
	Vector2		_position;
	Direction	_direction;
	EnemyState	_state;

	void spawnAction(Timer& timer);
	void idleAction(Timer& timer);

public:
	Enemy(Scene* scene, Vector2 position, Direction direction);
	~Enemy();

	void setState(EnemyState state);
	EnemyState getState() { return _state; }

	void update(Timer& timer);

};