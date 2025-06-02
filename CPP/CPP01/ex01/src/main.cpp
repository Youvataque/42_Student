#include "includes.hpp"

int main() {
	Zombie* zombH = zombieHorde(10, "toto");
	for (int i = 0; i < 10; i++) {
		zombH[i].announce();
	}
	delete[] zombH;
}