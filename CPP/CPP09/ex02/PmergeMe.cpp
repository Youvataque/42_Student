#include "PmergeMe.hpp"
#include <cstddef>

/////////////////////////////////////////////////////////////////////////// constructeur privé
PmergeMe::PmergeMe(): _vector(), _list() {}

/////////////////////////////////////////////////////////////////////////// méthodes privées
void PmergeMe::_selectionV(std::vector<unsigned int>& a) {
    for (std::size_t i = 0; i < a.size(); ++i) {
        std::size_t min_idx = i;
        for (std::size_t j = i + 1; j < a.size(); ++j) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            unsigned int temp = a[i];
            a[i] = a[min_idx];
            a[min_idx] = temp;
        }
    }
}

void PmergeMe::_selectionL(std::list<unsigned int>& a) {
	std::list<unsigned int>::iterator begin = a.begin();
    while (begin != a.end()) {
		std::list<unsigned int>::iterator begin2 = begin;
		begin2++;
		std::list<unsigned int>::iterator minIt = begin;
		while (begin2 != a.end()) {
			if (*begin2 < *minIt) {
				minIt = begin2;
			}
			begin2++;
		}
		if (minIt != begin) {
			unsigned int temp = *begin;
			*begin = *minIt;
			*minIt = temp;
		}
		begin++;
	}
}

/////////////////////////////////////////////////////////////////////////// constructeur
PmergeMe::PmergeMe(std::vector<unsigned int> vector, std::list<unsigned int> list): _vector(vector), _list(list) {}

PmergeMe::PmergeMe(const PmergeMe& other): _vector(other._vector), _list(other._list) {
}

PmergeMe::~PmergeMe() {}

/////////////////////////////////////////////////////////////////////////// opérateur d'affectation
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		this->_vector = other._vector;
		this->_list = other._list;
	}
	return *this;
}

/////////////////////////////////////////////////////////////////////////// getter / setter
std::vector<unsigned int> PmergeMe::getVector() const {
	return this->_vector;
}

std::list<unsigned int> PmergeMe::getList() const {
	return this->_list;
}

/////////////////////////////////////////////////////////////////////////// méthodes
void	PmergeMe::sortVector() {
	std::vector<unsigned int> A;
	std::vector<unsigned int> B;
	bool hasImp = false;
	unsigned int imp;

	std::size_t len = this->_vector.size();
	if ( len == 0 || len == 1)
		return ;
	if (len == 2 && this->_vector.at(0) < this->_vector.at(1))
		return ;
	if (len == 2 && this->_vector.at(0) > this->_vector.at(1)) {
		unsigned int temp = this->_vector.at(0);
		this->_vector.at(0) = this->_vector.at(1);
		this->_vector.at(1) = temp;
		return ;
	}
	if (len % 2 != 0) {
		imp = *(this->_vector.end() - 1);
		hasImp = true;
		this->_vector.erase(this->_vector.end() - 1);
	}
	for (std::size_t i = 0; i + 1 < this->_vector.size(); i+=2) {
		if (this->_vector.at(i) < this->_vector.at(i + 1)) {
			A.push_back(this->_vector.at(i + 1));
			B.push_back(this->_vector.at(i));
		} else {
			B.push_back(this->_vector.at(i + 1));
			A.push_back(this->_vector.at(i));
		}
	}
	if (hasImp)
		A.push_back(imp);
	_selectionV(A);
	for (size_t i = 0; i < B.size(); i++) {
		unsigned int el = B.at(i);
		std::vector<unsigned int>::iterator it = A.begin();
		while (it != A.end() && el > *it)
			it++;
		A.insert(it, el);
	}
	this->_vector = A;
}

void	PmergeMe::sortList() {
	std::list<unsigned int> A;
	std::list<unsigned int> B;
	bool hasImp = false;
	unsigned int imp;
	std::list<unsigned int>::iterator begin = this->_list.begin();
	std::list<unsigned int>::iterator end = this->_list.end();
	std::list<unsigned int>::iterator last = end;
	--last;

	std::size_t len = this->_list.size();
	if ( len == 0 || len == 1)
		return ;
	if (len == 2 && *begin < *last)
		return ;
	if (len == 2 && *begin > *last) {
		unsigned int temp = *begin;
		*begin = *last;
		*last = temp;
		return ;
	}
	if (len % 2 != 0) {
		imp = *last;
		hasImp = true;
		this->_list.erase(last);
		end = this->_list.end();
	}
	std::list<unsigned int>::iterator first = this->_list.begin();
	std::list<unsigned int>::iterator second = first;
	second++;
	while (second != end) {
		if (*first < *second) {
			A.push_back(*second);
			B.push_back(*first);
		} else {
			A.push_back(*first);
			B.push_back(*second);
		}
		++second;
		first = second;
		if (second == end)
			break;
		++second;
	}
	if (hasImp)
		A.push_back(imp);
	_selectionL(A);
	std::list<unsigned int>::iterator Bbegin = B.begin();
	while (Bbegin != B.end()) {
		std::list<unsigned int>::iterator it = A.begin();
		while (it != A.end() && *Bbegin > *it)
			it++;
		A.insert(it, *Bbegin);
		Bbegin++;
	}
	this->_list = A;
}

void	PmergeMe::fordJonsonSort() {
	try {
		sortVector();
		sortList();
	} catch (std::exception& error) {
		throw error;
	}
}
