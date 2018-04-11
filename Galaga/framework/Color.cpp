#include "Color.h"
#include "Color32.h"

Color::Color()
	:r(0)
	, g(0)
	, b(0)
{	}

Color::Color(const float red, const float green, const float blue)
	: r(red)
	, g(green)
	, b(blue)
{	}

Color::Color(const float* arr)
	: r(arr[0])
	, g(arr[1])
	, b(arr[2])
{	}

Color::Color(const Color& color)
	: r(color.r)
	, g(color.g)
	, b(color.b)
{	}

Color::Color(const Color&& color)
	: r(color.r)
	, g(color.g)
	, b(color.b)
{	}

Color::Color(const Color32& color)
	: r(static_cast<float>(color.r / 255.0f))
	, g(static_cast<float>(color.g / 255.0f))
	, b(static_cast<float>(color.b / 255.0f))
{	}

Color::~Color()
{   }

Color Color::operator+(const Color& color) const
{
	return Color(r + color.r, g + color.g, b + color.b);
}

Color Color::operator-(const Color& color) const
{
	return Color(r - color.r, g - color.g, b - color.b);
}

Color Color::operator*(const Color& color) const
{
	return Color(r * color.r, g * color.g, b * color.b);
}

Color Color::operator/(const Color& color) const
{
	return Color(r / color.r, g / color.g, b / color.b);
}

Color Color::operator+(const float value) const
{
	return Color(r + value, g + value, b + value);
}

Color Color::operator-(const float value) const
{
	return Color(r - value, g - value, b - value);
}

Color Color::operator*(const float value) const
{
	return Color(r * value, g * value, b * value);
}

Color Color::operator/(const float value) const
{
	return Color(r / value, g / value, b / value);
}

Color& Color::operator+=(const Color& color)
{
	r += color.r;
	g += color.g;
	b += color.b;
	return *this;
}

Color& Color::operator-=(const Color& color)
{
	r -= color.r;
	g -= color.g;
	b -= color.b;
	return *this;
}

Color& Color::operator*=(const Color& color)
{
	r *= color.r;
	g *= color.g;
	b *= color.b;
	return *this;
}

Color& Color::operator/=(const Color& color)
{
	r /= color.r;
	g /= color.g;
	b /= color.b;
	return *this;
}

Color& Color::operator+=(const float value)
{
	r += value;
	g += value;
	b += value;
	return *this;
}

Color& Color::operator-=(const float value)
{
	r -= value;
	g -= value;
	b -= value;
	return *this;
}

Color& Color::operator*=(const float value)
{
	r *= value;
	g *= value;
	b *= value;
	return *this;
}

Color& Color::operator/=(const float value)
{
	r /= value;
	g /= value;
	b /= value;
	return *this;
}

Color& Color::operator=(const Color& color)
{
	r = color.r;
	g = color.g;
	b = color.b;
	return *this;
}

Color& Color::operator=(const Color32& color)
{
	r = static_cast<float>(color.r / 255.0f);
	g = static_cast<float>(color.g / 255.0f);
	b = static_cast<float>(color.b / 255.0f);
	return *this;
}

bool Color::operator==(const Color& color) const
{
	return (r == color.r && g == color.g && b == color.b);
}

bool Color::operator==(const Color32& color) const
{
	return (r == static_cast<float>(color.r / 255.0f) && g == static_cast<float>(color.g / 255.0f) && b == static_cast<float>(color.b / 255.0f));
}

bool Color::operator!=(const Color& color) const
{
	return (r != color.r || g != color.g || b != color.b);
}

bool Color::operator!=(const Color32& color) const
{
	return (r != static_cast<float>(color.r / 255.0f) || g != static_cast<float>(color.g / 255.0f) || b != static_cast<float>(color.b / 255.0f));
}

const Color Color::white	( 1.0f,  1.0f,  1.0f);
const Color Color::yellow	( 1.0f,  1.0f,  0.0f);
const Color Color::blue		( 0.0f,  0.0f,  1.0f);
const Color Color::green	( 0.0f,  1.0f,  0.0f);
const Color Color::red		( 1.0f,  0.0f,  0.0f);
const Color Color::magenta	( 1.0f,  0.0f,  1.0f);
const Color Color::black	( 0.0f,  0.0f,  0.0f);
const Color Color::orange	( 1.0f,  0.5f,  0.0f);
const Color Color::gray		(0.65f, 0.65f, 0.65f);