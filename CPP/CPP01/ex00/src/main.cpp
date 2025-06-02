#include "includes.hpp"

int main() {
	Zombie* zomb1 = newZombie("toto");
	zomb1->announce();
	delete zomb1;
	randomChump("toto2");
}