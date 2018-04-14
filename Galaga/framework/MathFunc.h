#pragma once

inline float toRad(float deg)
{
	return deg * 0.017453f;
}

inline float toDeg(float rad)
{
	return rad * 57.295779f;
}

inline float pi()
{
	return 3.141592f;
}

inline float lerp(float v1, float v2, float amount)
{
	return (v1 + (v2 - v1) * amount);
}

template <typename T>
inline T clamp(T value, T min, T max)
{
	if (value > max)
	{
		return max;
	}
	else if (value < min)
	{
		return min;
	}
	return value;
}