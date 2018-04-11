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
	Texture();
	virtual ~Texture();

	virtual bool init() = 0;

};