#include <iostream>
#include <fstream>
#include <string>

int checkArgs(int ac, char **av, std::ifstream& inFile) {
	if (ac < 4 || ac > 4) {
		std::cout << "Error, need 3 arguments !\n";
		return 0;
	}
	inFile.open(av[1]);
	if (!inFile.is_open()) {
		std::cout << "Error opening file: " 
				  << av[1]
				  << "\n";
		return 0;
	}
	return 1;
}

int replaceAll(std::ifstream& inFile, std::ofstream& outFile, char **av) {
	std::string line;
	while (std::getline(inFile, line)) {
		size_t index;
		while ((index = line.find(av[2])) != std::string::npos) {
			line.erase(index, std::string(av[2]).length());
			line.insert(index, av[3]);
			index += std::string(av[3]).length();
		}
		outFile << line << std::endl;
	}
	return 1;
}

int main(int ac, char **av) {
	std::ifstream inFile;
	if (!checkArgs(ac, av, inFile)) {
		return 1;
	}
	std::ofstream outFile(std::string(av[1]) + ".replace");
	if (!replaceAll(inFile, outFile, av)) {
		return 1;
	} 
	return 0;
}