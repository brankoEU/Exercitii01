#include <random>

class Generator {
	std::uniform_int_distribution<int> dis;
	std::mt19937 gen;
public:
	Generator(int lower = 33, int upper = 126)
		: gen(std::random_device()()), dis(lower, upper) {}

	int operator()() {
		return dis(gen);
	}
};
