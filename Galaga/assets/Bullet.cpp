#include "Bullet.h"
#include "../Config.h"

Bullet::Bullet(Scene* scene)
	: _sprite(nullptr)
{	
	_sprite = Sprite::create("Bullet");
	_sprite->setActive(false);
	scene->addObject(_sprite);

	_rect.SetRect(
		_sprite->getPosition().x, _sprite->getPosition().y
		, 3.0f, 20.0f);
}

Bullet::~Bullet()
{	}

void Bullet::spawn(const Vector2& position)
{
	_sprite->setPosition(position);
	_sprite->setActive(true);
}

void Bullet::update(Timer& timer)
{
	if (!_sprite->isActive())
	{
		return;
	}

	_rect.SetRect(
		_sprite->getPosition().x, _sprite->getPosition().y
		, 3.0f, 20.0f);

	_sprite->setPosition(Vector2(
		_sprite->getPosition().x,
		_sprite->getPosition().y + 500.0f * timer.getDeltaTime()));
	if (_sprite->getPosition().y > SCREEN_WIDTH)
	{
		_sprite->setActive(false);
	}
}

void Bullet::setActive(bool active)
{
	_sprite->setActive(active);
}