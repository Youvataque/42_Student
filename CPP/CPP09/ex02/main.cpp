#include "PmergeMe.hpp"
#include <sstream>
#include <ctime>
#include <iomanip>

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: ./PmergeMe <liste d'entiers positifs>" << std::endl;
        return 1;
    }
    
    std::vector<unsigned int> vec;
    std::list<unsigned int> lst;
    
    for (int i = 1; i < argc; ++i) {
        std::istringstream iss(argv[i]);
        int n;
        if (!(iss >> n) || n < 0) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        vec.push_back(static_cast<unsigned int>(n));
        lst.push_back(static_cast<unsigned int>(n));
    }
    
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;
    
    clock_t start_vector = clock();
    PmergeMe pm(vec, lst);
    pm.sortVector();
    clock_t end_vector = clock();
    double duration_vector = static_cast<double>(end_vector - start_vector) * 1000000.0 / CLOCKS_PER_SEC;
    
    clock_t start_list = clock();
    pm.sortList();
    clock_t end_list = clock();
    double duration_list = static_cast<double>(end_list - start_list) * 1000000.0 / CLOCKS_PER_SEC;
    
    std::cout << "After: ";
    std::vector<unsigned int> sorted_vec = pm.getVector();
    for (size_t i = 0; i < sorted_vec.size(); ++i) {
        std::cout << sorted_vec[i];
        if (i < sorted_vec.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " 
              << std::fixed << std::setprecision(5) << duration_vector << " us" << std::endl;
    std::cout << "Time to process a range of " << vec.size() << " elements with std::list : " 
              << std::fixed << std::setprecision(5) << duration_list << " us" << std::endl;
    
    return 0;
}
