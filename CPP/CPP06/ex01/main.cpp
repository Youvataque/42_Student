#include <iostream>
#include <string>
#include <cstdint> // pour uintptr_t
#include "Serializer.hpp"

void printline(const std::string& title) {
	std::cout << "\033[1;36m" << title << "\033[0m" << std::endl;
}

int main() {
	printline("=== TEST SERIALIZER ===");

	// Création d'une instance de Data
	Data original;
	original.id = 42;
	original.name = "Yannis";
	original.score = 3.14f;

	// Affichage des valeurs initiales
	std::cout << "Original Data address : " << &original << std::endl;
	std::cout << "Original content      : { id = " << original.id
	          << ", name = " << original.name
	          << ", score = " << original.score << " }" << std::endl;

	// Sérialisation
	uintptr_t raw = Serializer::serialize(&original);
	std::cout << "Serialized uintptr_t  : " << raw << std::endl;

	// Désérialisation
	Data* restored = Serializer::deserialize(raw);
	std::cout << "Restored Data address : " << restored << std::endl;

	// Vérification de l'identité du pointeur
	if (restored == &original)
		std::cout << "✅ Success: pointer restored correctly!" << std::endl;
	else
		std::cout << "❌ Failure: pointer mismatch!" << std::endl;

	// Affichage des données restaurées
	std::cout << "Restored content      : { id = " << restored->id
	          << ", name = " << restored->name
	          << ", score = " << restored->score << " }" << std::endl;

	return 0;
}