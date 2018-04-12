#include "Texture.h"

Texture::Texture(const string& key)
    : _buffer(0)
{
    _key = key;
}

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
