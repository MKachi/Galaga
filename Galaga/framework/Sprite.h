#pragma once

#include "Node.h"
#include "Texture.h"
#include "MathFunc.h"

class Sprite
	: public Node
{
private:
	Texture* _texture;

public:
	Sprite(Texture* texture);
	virtual ~Sprite();

	void render() override;

};