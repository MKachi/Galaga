#pragma once

#include "Node.h"
#include "Texture.h"
#include "MathFunc.h"

class Sprite
	: public Node
{
private:
	Texture* _texture;

	bool init(const string& textureKey);

public:
	Sprite();
	virtual ~Sprite();

	static Sprite* create(const string& textureKey);

	void render() override;

};