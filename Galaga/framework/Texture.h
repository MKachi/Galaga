#pragma once

#if _WINDOWS
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif
#include "Cache.h"

class Texture
	: public Cache
{
protected:
	GLuint _buffer;

	void glListBegin();
	void glListEnd();

public:
	Texture(const string& key);
	virtual ~Texture();

	virtual bool init() = 0;

};