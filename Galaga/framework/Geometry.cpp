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
