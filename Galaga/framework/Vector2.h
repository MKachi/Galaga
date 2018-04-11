#pragma once

class Vector2 final
{
public:
	union
	{
		struct { float x, y; };
		float toArray[2];
	};
	Vector2();
	Vector2(float value);
	Vector2(float x, float y);
	Vector2(const float* array);
	Vector2(const Vector2& rhs);
	Vector2(Vector2&& rhs);
	~Vector2() = default;

	Vector2 operator+(const Vector2& rhs) const;
	Vector2 operator-(const Vector2& rhs) const;
	Vector2 operator*(const Vector2& rhs) const;
	Vector2 operator/(const Vector2& rhs) const;

	Vector2 operator+(float value) const;
	Vector2 operator-(float value) const;
	Vector2 operator*(float value) const;
	Vector2 operator/(float value) const;

	Vector2& operator+=(const Vector2& rhs);
	Vector2& operator-=(const Vector2& rhs);
	Vector2& operator*=(const Vector2& rhs);
	Vector2& operator/=(const Vector2& rhs);
	Vector2& operator=(const Vector2& rhs);

	Vector2& operator+=(float value);
	Vector2& operator-=(float value);
	Vector2& operator*=(float value);
	Vector2& operator/=(float value);
	Vector2& operator=(float value);

	Vector2 operator-() const;

	bool operator<(const Vector2& rhs) const;
	bool operator<=(const Vector2& rhs) const;
	bool operator>(const Vector2& rhs) const;
	bool operator>=(const Vector2& rhs) const;

	bool operator==(const Vector2& rhs) const;
	bool operator!=(const Vector2& rhs) const;

	bool isZero() const;
	bool isOne() const;

	Vector2 normalize();
	static Vector2 normalize(const Vector2& other);

	float length() const;
	float distance(const Vector2& other) const;
	static float distance(const Vector2& other1, const Vector2& other2);

	float dot(const Vector2& other) const;
	static float dot(const Vector2& other1, const Vector2& other2);

	static const Vector2 zero;
	static const Vector2 one;

	static const Vector2 up;
	static const Vector2 down;
	static const Vector2 left;
	static const Vector2 right;

	static const Vector2 axisX;
	static const Vector2 axisY;

};