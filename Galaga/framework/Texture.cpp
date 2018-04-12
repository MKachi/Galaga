#include "Texture.h"

Texture::Texture(const string& key)
	: _key(key)
	, _buffer(0)
{	}

Texture::~Texture()
{
	if (_buffer != 0)
	{
		glDeleteLists(_buffer, 1);
		_buffer = 0;
	}
}

void Texture::glListBegin()
{
	_buffer = glGenLists(1);
	glNewList(_buffer, GL_COMPILE);
}

void Texture::glListEnd()
{
	glEndList();
}