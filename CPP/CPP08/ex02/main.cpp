#include "MutantStack.hpp"
#include <list>
#include <vector>
#include <iostream>
#include <string>

// Couleurs ANSI
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

void printSection(const std::string& title, const std::string& color = CYAN) {
    std::cout << color << "\n==================== " << title << " ====================\n" << RESET;
}

template<typename T>
void printContainer(const T& container, const std::string& label) {
    std::cout << YELLOW << label << ": [ ";
    for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << "]" << RESET << std::endl;
}

int main() {
    printSection("Test de base : push/pop/top", GREEN);
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top : " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Après pop, taille : " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    printContainer(mstack, "Contenu du MutantStack");

    printSection("Itération normale", BLUE);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    std::cout << "Itération : ";
    for (; it != ite; ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    printSection("Itération constante", MAGENTA);
    MutantStack<int>::const_iterator cit = mstack.begin();
    MutantStack<int>::const_iterator cite = mstack.end();
    std::cout << "Itération const : ";
    for (; cit != cite; ++cit)
        std::cout << *cit << " ";
    std::cout << std::endl;

    printSection("Itération reverse", YELLOW);
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    std::cout << "Reverse : ";
    for (; rit != rite; ++rit)
        std::cout << *rit << " ";
    std::cout << std::endl;

    printSection("Itération reverse const", RED);
    MutantStack<int>::const_reverse_iterator rcit = mstack.rbegin();
    MutantStack<int>::const_reverse_iterator rcite = mstack.rend();
    std::cout << "Reverse const : ";
    for (; rcit != rcite; ++rcit)
        std::cout << *rcit << " ";
    std::cout << std::endl;

    printSection("Test de copie et d'affectation", CYAN);
    MutantStack<int> copy(mstack);
    MutantStack<int> assign;
    assign = mstack;
    printContainer(copy, "Copie du MutantStack");
    printContainer(assign, "Affectation du MutantStack");

    printSection("Comparaison avec std::list", GREEN);
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    lst.pop_back();
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    printContainer(lst, "Contenu de la std::list");
    std::cout << "Itération list : ";
    for (std::list<int>::iterator lit = lst.begin(); lit != lst.end(); ++lit)
        std::cout << *lit << " ";
    std::cout << std::endl;

    printSection("Test avec d'autres types (string)", MAGENTA);
    MutantStack<std::string> mstackStr;
    mstackStr.push("Hello");
    mstackStr.push("World");
    mstackStr.push("42");
    printContainer(mstackStr, "MutantStack<string>");
    std::cout << "Itération string : ";
    for (MutantStack<std::string>::iterator sit = mstackStr.begin(); sit != mstackStr.end(); ++sit)
        std::cout << *sit << " ";
    std::cout << std::endl;

    printSection("Test const correctness", YELLOW);
    const MutantStack<int> constStack = mstack;
    std::cout << "Itération constStack : ";
    for (MutantStack<int>::const_iterator cit2 = constStack.begin(); cit2 != constStack.end(); ++cit2)
        std::cout << *cit2 << " ";
    std::cout << std::endl;

    printSection("Fin des tests MutantStack", GREEN);
    return 0;
}
