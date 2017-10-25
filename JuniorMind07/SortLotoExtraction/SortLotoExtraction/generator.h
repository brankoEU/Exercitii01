#pragma once
#include <random>

class Generator {
	std::uniform_int_distribution<int> dis;
	std::mt19937 gen;
public:
	Generator(int lower = 1, int upper = 32000)
		: gen(std::random_device()()), dis(lower, upper) {}

	int operator()() {
		return dis(gen);
	}
};

