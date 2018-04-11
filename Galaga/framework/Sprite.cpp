#include "Sprite.h"

Sprite::Sprite(Texture* texture)
	: _texture(texture)
{	
	_texture->retain();
}

Sprite::~Sprite()
{
	_texture->release();

	for (auto child : _children)
	{
		SAFE_DELETE(child);
	}
}

void Sprite::render()
{
	glTranslatef(_position.x, _position.y, 0.0f);
	glRotatef(_rotate, 0.0f, 0.0f, 1.0f);
	glScalef(_scale.x, _scale.y, 1.0f);

	for (auto& child : _children)
	{
		child->render();
	}
}