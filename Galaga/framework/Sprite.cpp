#include "Sprite.h"
#include <algorithm>

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
	glPushMatrix();

	std::sort(_children.begin(), _children.end()
		, [](Node* a, Node* b)-> bool
	{
		return a->getDepth() < b->getDepth();
	});

	for (auto& child : _children)
	{
		child->render();
	}
	glPopMatrix();
}