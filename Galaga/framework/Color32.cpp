#include "Color32.h"
#include "Color.h"

Color32::Color32()
	:r(0)
	, g(0)
	, b(0)
{	}

Color32::Color32(byte red, byte green, byte blue)
	: r(red)
	, g(green)
	, b(blue)
{	}

Color32::Color32(const byte* arr)
	: r(arr[0])
	, g(arr[1])
	, b(arr[2])
{	}

Color32::Color32(const Color32& color)
	: r(color.r)
	, g(color.g)
	, b(color.b)
{	}

Color32::Color32(Color32&& color)
	: r(color.r)
	, g(color.g)
	, b(color.b)
{	}

Color32::Color32(const Color& color)
	: r(static_cast<byte>(color.r * 255))
	, g(static_cast<byte>(color.g * 255))
	, b(static_cast<byte>(color.b * 255))
{	}

Color32::~Color32()
{	}

Color32 Color32::operator+(const Color32& color) const
{
	return Color32(r + color.r, g + color.g, b + color.b);
}

Color32 Color32::operator-(const Color32& color) const
{
	return Color32(r - color.r, g - color.g, b - color.b);
}

Color32 Color32::operator*(const Color32& color) const
{
	return Color32(r * color.r, g * color.g, b * color.b);
}

Color32 Color32::operator/(const Color32& color) const
{
	return Color32(r / color.r, g / color.g, b / color.b);
}

Color32 Color32::operator+(float value) const
{
	return Color32(r + value, g + value, b + value);
}

Color32 Color32::operator-(float value) const
{
	return Color32(r - value, g - value, b - value);
}

Color32 Color32::operator*(float value) const
{
	return Color32(r * value, g * value, b * value);
}

Color32 Color32::operator/(float value) const
{
	return Color32(r / value, g / value, b / value);
}

Color32& Color32::operator+=(const Color32& color)
{
	r += color.r;
	g += color.g;
	b += color.b;
	return *this;
}

Color32& Color32::operator-=(const Color32& color)
{
	r -= color.r;
	g -= color.g;
	b -= color.b;
	return *this;
}

Color32& Color32::operator*=(const Color32& color)
{
	r *= color.r;
	g *= color.g;
	b *= color.b;
	return *this;
}

Color32& Color32::operator/=(const Color32& color)
{
	r /= color.r;
	g /= color.g;
	b /= color.b;
	return *this;
}

Color32& Color32::operator+=(float value)
{
	r += value;
	g += value;
	b += value;
	return *this;
}

Color32& Color32::operator-=(float value)
{
	r -= value;
	g -= value;
	b -= value;
	return *this;
}

Color32& Color32::operator*=(float value)
{
	r *= value;
	g *= value;
	b *= value;
	return *this;
}

Color32& Color32::operator/=(float value)
{
	r /= value;
	g /= value;
	b /= value;
	return *this;
}

Color32& Color32::operator=(const Color32& color)
{
	r = color.r;
	g = color.g;
	b = color.b;
	return *this;
}

Color32& Color32::operator=(const Color& color)
{
	r = static_cast<byte>(color.r * 255);
	g = static_cast<byte>(color.g * 255);
	b = static_cast<byte>(color.b * 255);
	return *this;
}

bool Color32::operator==(const Color32& color) const
{
	return (r == color.r && g == color.g && b == color.b);
}

bool Color32::operator==(const Color& color) const
{
	return (r == static_cast<byte>(color.r * 255) && g == static_cast<byte>(color.g * 255) && b == static_cast<byte>(color.b * 255));
}

bool Color32::operator!=(const Color32& color) const
{
	return (r != color.r || g != color.g || b != color.b);
}

bool Color32::operator!=(const Color& color) const
{
	return (r != static_cast<byte>(color.r * 255) || g != static_cast<byte>(color.g * 255) || b != static_cast<byte>(color.b * 255));
}

const Color32 Color32::white	(255, 255, 255);
const Color32 Color32::yellow	(255, 255,   0);
const Color32 Color32::blue		(  0,   0, 255);
const Color32 Color32::green	(  0, 255,   0);
const Color32 Color32::red		(255,   0,   0);
const Color32 Color32::magenta	(255,   0, 255);
const Color32 Color32::black	(  0,   0,   0);
const Color32 Color32::orange	(255, 127,   0);
const Color32 Color32::gray		(166, 166, 166);