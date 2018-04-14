#include "Geometry.h"

Size::Size()
	: width(0)
	, height(0)
{	}

Size::Size(const uint w, const uint h)
	: width(w)
	, height(h)
{	}

Size::Size(const Size& size)
	: width(size.width)
	, height(size.height)
{	}

Size::Size(Size&& size)
	: width(size.width)
	, height(size.height)
{	}

Size::~Size()
{	}

Size& Size::operator=(const Size& rhs)
{
	setSize(rhs.width, rhs.height);
	return *this;
}

Size Size::operator+(const Size& rhs) const
{
	return Size(width + rhs.width, height + rhs.height);
}

Size Size::operator*(uint value) const
{
	return Size(width * value, height * value);
}

Size Size::operator/(uint value) const
{
	return Size(width / value, height / value);
}

void Size::setSize(const uint w, const uint h)
{
	width = w;
	height = h;
}

const Size Size::zero(0, 0);
const Size Size::one(1, 1);

Rect::Rect()
{
	SetRect(0.0f, 0.0f, 0.0f, 0.0f);
}

Rect::Rect(float xx, float yy, float w, float h)
{
	SetRect(xx, yy, w, h);
}

Rect::Rect(const Vector2& origin, const Size& size)
{
	this->origin = origin;
	this->size = size;
}

Rect::Rect(const Rect& rect)
{
	SetRect(rect.origin.x, rect.origin.y, rect.size.width, rect.size.height);
}

Rect::Rect(const Rect&& rect)
{
	SetRect(rect.origin.x, rect.origin.y, rect.size.width, rect.size.height);
}

Rect::~Rect()
{   }

Rect& Rect::operator=(const Rect& rect)
{
	SetRect(rect.origin.x, rect.origin.y, rect.size.width, rect.size.height);
	return *this;
}

void Rect::SetRect(float x, float y, float w, float h)
{
	origin.x = x;
	origin.y = y;
	size.width = w;
	size.height = h;
}