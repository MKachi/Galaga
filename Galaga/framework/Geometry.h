#pragma once

#include "Rule.h"
#include "Vector2.h"

class Size final
{
public:
	uint width;
	uint height;

	Size();
	Size(const uint w, const uint h);
	Size(const Size& rhs);
	Size(Size&& rhs);
	~Size();

	Size& operator=(const Size& rhs);
	Size operator+(const Size& rhs) const;
	Size operator*(uint value) const;
	Size operator/(uint value) const;

	void setSize(const uint w, const uint h);

	static const Size zero;
	static const Size one;

};

class Rect final
{
public:
	Vector2 origin;
	Size size;

	Rect();
	Rect(const float x, const float y, const float w, const float h);
	Rect(const Vector2& origin, const Size& size);
	Rect(const Rect& rect);
	Rect(const Rect&& rect);
	~Rect();

	Rect& operator=(const Rect& rect);

	void SetRect(float x, float y, float w, float h);

};