#pragma once

#include <random>

inline int random(int min, int max)
{
	std::random_device rd;
	std::mt19937_64 rng(rd());
	std::uniform_int_distribution<int> dist(min, max);
	return dist(rng);
}

inline float random(float min, float max)
{
	std::random_device rd;
	std::mt19937_64 rng(rd());
	std::uniform_real_distribution<float> dist(min, max);
	return dist(rng);
}