#pragma once

#include <random>

class Random
{
public:
	static int GetIntRange(int min, int max)
	{
		std::random_device rd;
		std::mt19937 generator;
		generator.seed(rd());
		std::uniform_int_distribution<int> dist(min, max);
		return dist(generator);
	};
};
