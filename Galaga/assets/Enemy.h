#pragma once

#include "../framework/Sprite.h"
#include "../framework/Scene.h"
#include "../framework/Scheduler.h"
#include "../framework/Geometry.h"

enum class EnemyState
{
	None,
	Die,
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
	Vector2		_movePosition;
	Direction	_direction;
	EnemyState	_state;
	Scheduler*	_scheduler;
	Rect		_rect;

	void spawnAction(Timer& timer);
	void idleAction(Timer& timer);

	void nextAction(float dt);
	void respawn(float dt);

public:
	Enemy(Scene* scene, Vector2 position, Direction direction);
	~Enemy();

	void setState(EnemyState state);
	EnemyState getState() { return _state; }

	void update(Timer& timer);

	Rect getRect() { return _rect; }

};