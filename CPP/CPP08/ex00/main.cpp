#include <list>
#include "easyfind.hpp"

// Couleurs ANSI
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"
#define MAGENTA "\033[35m"

void printSection(const std::string& title) {
    std::cout << std::endl
              << CYAN << "==================== " << title << " ====================" << RESET
              << std::endl;
}

template<typename T>
void printContainer(const T& container, const std::string& label) {
    std::cout << YELLOW << label << ": [ ";
    for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << "]" << RESET << std::endl;
}

void testVectorFound() {
    printSection("TEST VECTOR - VALEUR TROUVÉE");

    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    int search = 30;

    printContainer(vec, "Contenu du vector");
    std::cout << BLUE << "Recherche de la valeur : " << search << RESET << std::endl;

    try {
        std::vector<int>::iterator it = easyfind(vec, search);
        std::cout << GREEN << "✅ Trouvé : " << *it << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cerr << RED << "❌ Erreur : " << e.what() << RESET << std::endl;
    }
}

void testVectorNotFound() {
    printSection("TEST VECTOR - VALEUR ABSENTE");

    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    int search = 99;

    printContainer(vec, "Contenu du vector");
    std::cout << BLUE << "Recherche de la valeur : " << search << RESET << std::endl;

    try {
        std::vector<int>::iterator it = easyfind(vec, search);
        std::cout << GREEN << "✅ Trouvé : " << *it << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cerr << RED << "❌ Erreur : " << e.what() << RESET << std::endl;
    }
}

void testListFound() {
    printSection("TEST LIST - VALEUR TROUVÉE");

    std::list<int> lst;
    lst.push_back(7);
    lst.push_back(14);
    lst.push_back(21);

    int search = 14;

    printContainer(lst, "Contenu de la list");
    std::cout << BLUE << "Recherche de la valeur : " << search << RESET << std::endl;

    try {
        std::list<int>::iterator it = easyfind(lst, search);
        std::cout << GREEN << "✅ Trouvé : " << *it << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cerr << RED << "❌ Erreur : " << e.what() << RESET << std::endl;
    }
}

void testListNotFound() {
    printSection("TEST LIST - VALEUR ABSENTE");

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(6);
    lst.push_back(7);

    int search = 42;

    printContainer(lst, "Contenu de la list");
    std::cout << BLUE << "Recherche de la valeur : " << search << RESET << std::endl;

    try {
        std::list<int>::iterator it = easyfind(lst, search);
        std::cout << GREEN << "✅ Trouvé : " << *it << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cerr << RED << "❌ Erreur : " << e.what() << RESET << std::endl;
    }
}

int main() {
    printSection("DÉBUT DES TESTS EASYFIND");

    testVectorFound();
    testVectorNotFound();
    testListFound();
    testListNotFound();

    printSection("FIN DES TESTS");
    return 0;
}