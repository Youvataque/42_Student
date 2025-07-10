#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& tab, int n) {
	typename T::iterator here = std::find(tab.begin(), tab.end(), n);
	if (here == tab.end()) {
		throw std::out_of_range("easyfind: valeur non trouvée");
	} else {
		std::cout << "Valeur trouvée : " << *here << std::endl;
		return here;
	}
}