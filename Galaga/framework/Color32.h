#pragma once

#include "Rule.h"

class Color;
class Color32 final
{
public:
	union
	{
		struct { byte r, g, b; };
		byte toArray[3];
	};

	Color32();
	Color32(byte red, const byte green, byte blue);
	Color32(const byte* arr);
	Color32(const Color32& color);
	Color32(Color32&& color);
	Color32(const Color& color);
	~Color32();

	Color32 operator+(const Color32& color) const;
	Color32 operator-(const Color32& color) const;
	Color32 operator*(const Color32& color) const;
	Color32 operator/(const Color32& color) const;

	Color32 operator+(float value) const;
	Color32 operator-(float value) const;
	Color32 operator*(float value) const;
	Color32 operator/(float value) const;

	Color32& operator+=(const Color32& color);
	Color32& operator-=(const Color32& color);
	Color32& operator*=(const Color32& color);
	Color32& operator/=(const Color32& color);

	Color32& operator+=(float value);
	Color32& operator-=(float value);
	Color32& operator*=(float value);
	Color32& operator/=(float value);

	Color32& operator=(const Color32& color);
	Color32& operator=(const Color& color);

	bool operator==(const Color32& color) const;
	bool operator==(const Color& color) const;
	bool operator!=(const Color32& color) const;
	bool operator!=(const Color& color) const;

	bool operator<(const Color32&) = delete;
	bool operator>(const Color32&) = delete;
	Color32 operator-() = delete;

	const static Color32 white;
	const static Color32 yellow;
	const static Color32 blue;
	const static Color32 green;
	const static Color32 red;
	const static Color32 magenta;
	const static Color32 black;
	const static Color32 orange;
	const static Color32 gray;
};