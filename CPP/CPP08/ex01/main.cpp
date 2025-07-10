#include "Span.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>

// Fonctions utilitaires pour l'affichage coloré
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

int main() {
    // Test de base
    printSection("Test de base", GREEN);
    Span test(10);
    test.addNumber(6);
    test.addNumber(3);
    test.addNumber(17);
    test.addNumber(9);
    test.addNumber(11);
    std::cout << "Contenu : " << test;
    std::cout << "Shortest span : " << test.shortestSpan() << std::endl;
    std::cout << "Longest span : " << test.longestSpan() << std::endl;

    // Test exception (moins de 2 éléments)
    printSection("Exception : moins de 2 éléments", RED);
    try {
        Span s(1);
        s.addNumber(42);
        std::cout << s.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception attrapée : " << e.what() << std::endl;
    }

    // Test exception (ajout au-delà de la capacité)
    printSection("Exception : dépassement de capacité", RED);
    try {
        Span s(2);
        s.addNumber(1);
        s.addNumber(2);
        s.addNumber(3);
    } catch (const std::exception& e) {
        std::cout << "Exception attrapée : " << e.what() << std::endl;
    }

    // Test avec des valeurs négatives et extrêmes
    printSection("Valeurs négatives et extrêmes", YELLOW);
    Span s2(5);
    s2.addNumber(-100);
    s2.addNumber(0);
    s2.addNumber(100);
    s2.addNumber(INT_MAX);
    s2.addNumber(INT_MIN);
    std::cout << "Contenu : " << s2;
    std::cout << "Shortest span : " << s2.shortestSpan() << std::endl;
    std::cout << "Longest span : " << s2.longestSpan() << std::endl;

    // Test de copie et d'affectation
    printSection("Copie et affectation", MAGENTA);
    Span original(3);
    original.addNumber(1);
    original.addNumber(2);
    original.addNumber(3);
    Span copie(original);
    Span affectation = original;
    std::cout << "Original : " << original;
    std::cout << "Copie : " << copie;
    std::cout << "Affectation : " << affectation;

    // Test sur un grand nombre d'éléments (10 000)
    printSection("Test performance 10 000 éléments", BLUE);
    Span big(10000);
    std::srand(static_cast<unsigned int>(std::time(0)));
    for (int i = 0; i < 10000; ++i) {
        big.addNumber(std::rand());
    }
    std::cout << "Shortest span (10 000) : " << big.shortestSpan() << std::endl;
    std::cout << "Longest span (10 000) : " << big.longestSpan() << std::endl;

    // Test avec tous les éléments identiques
    printSection("Tous les éléments identiques", YELLOW);
    Span identiques(5);
    for (int i = 0; i < 5; ++i) identiques.addNumber(42);
    std::cout << "Contenu : " << identiques;
    std::cout << "Shortest span : " << identiques.shortestSpan() << std::endl;
    std::cout << "Longest span : " << identiques.longestSpan() << std::endl;

    printSection("Fin des tests", GREEN);
    return 0;
}