#pragma once

#include "../framework/Sprite.h"
#include "../framework/Scene.h"
#include "../framework/Geometry.h"

class Bullet
{
private:
	Sprite* _sprite;
	Rect	_rect;

public:
	Bullet(Scene* scene);
	~Bullet();

	void spawn(const Vector2& position);
	void update(Timer& timer);

	Rect getRect() { return _rect; }
	bool isActive() { return _sprite->isActive(); }

};