#pragma once

#include "OpenGL.h"
#include "Cache.h"

class Texture
	: public Cache
{
protected:
	GLuint _buffer;

public:
	Texture(const string& key);
	virtual ~Texture();

	void glListBegin();
	void glListEnd();

	void bind();

};