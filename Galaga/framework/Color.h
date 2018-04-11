#pragma once

#include "Rule.h"

class Color32;
class Color final
{
public:
	union
	{
		struct { float r, g, b; };
		float toArray[3];
	};

	Color();
	Color(float red, float green, float blue);
	Color(const float* array);
	Color(const Color& color);
	Color(const Color&& color);
	Color(const Color32& color);
	~Color();

	Color operator+(const Color& color) const;
	Color operator-(const Color& color) const;
	Color operator*(const Color& color) const;
	Color operator/(const Color& color) const;

	Color operator+(const float value) const;
	Color operator-(const float value) const;
	Color operator*(const float value) const;
	Color operator/(const float value) const;

	Color& operator+=(const Color& color);
	Color& operator-=(const Color& color);
	Color& operator*=(const Color& color);
	Color& operator/=(const Color& color);

	Color& operator+=(const float value);
	Color& operator-=(const float value);
	Color& operator*=(const float value);
	Color& operator/=(const float value);

	Color& operator=(const Color& color);
	Color& operator=(const Color32& color);

	bool operator==(const Color& color) const;
	bool operator!=(const Color& color) const;
	bool operator==(const Color32& color) const;
	bool operator!=(const Color32& color) const;

	bool operator<(const Color&) = delete;
	bool operator>(const Color&) = delete;
	Color operator-() = delete;

	const static Color white;
	const static Color yellow;
	const static Color blue;
	const static Color green;
	const static Color red;
	const static Color magenta;
	const static Color black;
	const static Color orange;
	const static Color gray;
};