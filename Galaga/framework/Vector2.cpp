#include "Vector2.h"
#include <cmath>

Vector2::Vector2()
	: x(0.0f)
	, y(0.0f)
{	}

Vector2::Vector2(float value)
	: x(value)
	, y(value)
{	}

Vector2::Vector2(float x, float y)
	: x(x)
	, y(y)
{	}

Vector2::Vector2(const float* array)
	: x(array[0])
	, y(array[1])
{	}

Vector2::Vector2(const Vector2& rhs)
	: x(rhs.x)
	, y(rhs.y)
{	}

Vector2::Vector2(Vector2&& rhs)
	: x(rhs.x)
	, y(rhs.y)
{	
	rhs.x = 0.0f;
	rhs.y = 0.0f;
}

Vector2 Vector2::operator+(const Vector2& rhs) const
{
	return Vector2(x + rhs.x, y + rhs.y);
}

Vector2 Vector2::operator-(const Vector2& rhs) const
{
	return Vector2(x - rhs.x, y - rhs.y);
}

Vector2 Vector2::operator*(const Vector2& rhs) const
{
	return Vector2(x * rhs.x, y * rhs.y);
}

Vector2 Vector2::operator/(const Vector2& rhs) const
{
	return Vector2(x / rhs.x, y / rhs.y);
}

Vector2 Vector2::operator+(float value) const
{
	return Vector2(x + value, y + value);
}

Vector2 Vector2::operator-(float value) const
{
	return Vector2(x - value, y - value);
}

Vector2 Vector2::operator*(float value) const
{
	return Vector2(x * value, y * value);
}

Vector2 Vector2::operator/(float value) const
{
	return Vector2(x / value, y / value);
}

Vector2& Vector2::operator+=(const Vector2& rhs)
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

Vector2& Vector2::operator-=(const Vector2& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}

Vector2& Vector2::operator*=(const Vector2& rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	return *this;
}

Vector2& Vector2::operator/=(const Vector2& rhs)
{
	x /= rhs.x;
	y /= rhs.y;
	return *this;
}

Vector2& Vector2::operator=(const Vector2& rhs)
{
	x = rhs.x;
	y = rhs.y;

	return *this;
}

Vector2& Vector2::operator+=(float value)
{
	x += value;
	y += value;
	return *this;
}

Vector2& Vector2::operator-=(float value)
{
	x -= value;
	y -= value;
	return *this;
}

Vector2& Vector2::operator*=(float value)
{
	x *= value;
	y *= value;
	return *this;
}

Vector2& Vector2::operator/=(float value)
{
	x /= value;
	y /= value;
	return *this;
}

Vector2& Vector2::operator=(float value)
{
	x = value;
	y = value;
	return *this;
}

Vector2 Vector2::operator-() const
{
	return Vector2(-x, -y);
}

bool Vector2::operator<(const Vector2& rhs) const
{
	return (x < rhs.x && y < rhs.y);
}

bool Vector2::operator<=(const Vector2& rhs) const
{
	return (x <= rhs.x && y <= rhs.y);
}

bool Vector2::operator>(const Vector2& rhs) const
{
	return (x > rhs.x && y > rhs.y);
}

bool Vector2::operator>=(const Vector2& rhs) const
{
	return (x >= rhs.x && y >= rhs.y);
}

bool Vector2::operator==(const Vector2& rhs) const
{
	return (x == rhs.x && y == rhs.y);
}

bool Vector2::operator!=(const Vector2& rhs) const
{
	return (x != rhs.x || y != rhs.y);
}

bool Vector2::isZero() const
{
	return (x == 0.0f && y == 0.0f);
}

bool Vector2::isOne() const
{
	return (x == 1.0f && y == 1.0f);
}

Vector2 Vector2::normalize()
{
	float length = sqrt(x * x + y * y);
	return Vector2(x / length, y / length);
}

Vector2 Vector2::normalize(const Vector2& other)
{
	float length = sqrt(other.x * other.x + other.y * other.y);
	return Vector2(other.x / length, other.y / length);
}

float Vector2::length() const
{
	return sqrt(x * x + y * y);
}

float Vector2::distance(const Vector2& other) const
{
	float deltaX = other.x - x;
	float deltaY = other.y - y;
	return sqrt(deltaX * deltaX + deltaY * deltaY);
}

float Vector2::distance(const Vector2& other1, const Vector2& other2)
{
	float deltaX = other1.x - other2.x;
	float deltaY = other1.y - other2.y;
	return sqrt(deltaX * deltaX + deltaY * deltaY);
}

float Vector2::dot(const Vector2& other) const
{
	return x * other.x + y * other.y;
}

float Vector2::dot(const Vector2& other1, const Vector2& other2)
{
	return other1.x * other2.x + other1.y * other2.y;
}

const Vector2 Vector2::zero		( 0.0f,  0.0f );
const Vector2 Vector2::one		( 1.0f,  1.0f );
const Vector2 Vector2::up		( 0.0f,  1.0f );
const Vector2 Vector2::down		( 0.0f, -1.0f );
const Vector2 Vector2::left		(-1.0f,  0.0f );
const Vector2 Vector2::right	( 1.0f,  1.0f );
const Vector2 Vector2::axisX	( 1.0f,  0.0f );
const Vector2 Vector2::axisY	( 0.0f,  1.0f );