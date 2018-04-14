#pragma once

#include "../framework/Sprite.h"
#include "../framework/Scene.h"

enum class EnemyState
{
	SpawnAction,
	Idle,
};

class Enemy
{
private:
	Sprite*		_sprite;
	EnemyState	_state;
	Vector2		_position;

	void spawnAction(Timer& timer);
	void idleAction(Timer& timer);

public:
	Enemy(Scene* scene, Vector2 position);
	~Enemy();

	void setState(EnemyState state);
	EnemyState getState() { return _state; }

	void update(Timer& timer);

};