<<<<<<< HEAD
#ifndef GENERATOR_H
#define GENERATOR_H
=======
>>>>>>> a43f23bcbab71ce1fbdf359ba26d5ee9466d1b2e
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
<<<<<<< HEAD

#endif

=======
>>>>>>> a43f23bcbab71ce1fbdf359ba26d5ee9466d1b2e
