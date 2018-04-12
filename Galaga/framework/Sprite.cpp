#include "Sprite.h"
#include "CacheManager.h"
#include <algorithm>

Sprite::Sprite()
	: _texture(nullptr)
{	}

Sprite::~Sprite()
{
	_texture->release();

	for (auto child : _children)
	{
		SAFE_DELETE(child);
	}
}

Sprite* Sprite::create(const string& textureKey)
{
	Sprite* result = new (std::nothrow) Sprite();
	if (result != nullptr && result->init(textureKey))
	{
		return result;
	}
	return nullptr;
}

bool Sprite::init(const string& textureKey)
{
	_texture = CacheManager::getInstance()->get<Texture*>(textureKey);
	if (_texture == nullptr)
	{
		return false;
	}

	return true;
}

void Sprite::render()
{
	glTranslatef(_position.x, _position.y, 0.0f);
	glRotatef(_rotate, 0.0f, 0.0f, 1.0f);
	glScalef(_scale.x, _scale.y, 1.0f);
	glPushMatrix();

	_texture->bind();

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