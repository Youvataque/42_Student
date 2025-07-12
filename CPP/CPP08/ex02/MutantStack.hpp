#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <string>
#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> > {
private:
	/////////////////////////////////////////////////////////////////////////// méthodes privées

	/////////////////////////////////////////////////////////////////////////// attributs

public:
	/////////////////////////////////////////////////////////////////////////// constructeur
	MutantStack() {};
	
	MutantStack(const MutantStack& other) : std::stack<T, std::deque<T> >(other) {}

	~MutantStack() {};

	/////////////////////////////////////////////////////////////////////////// opérateur d'affectation
	MutantStack& operator=(const MutantStack& other) {
		if (this != &other) {
			std::stack<T, std::deque<T> >::operator=(other);
		}
		return *this;
	}
	

	/////////////////////////////////////////////////////////////////////////// names
	typedef typename std::stack<T, std::deque<T> >::container_type	container_type;
    typedef typename container_type::iterator               	iterator;
    typedef typename container_type::const_iterator         	const_iterator;
    typedef typename container_type::reverse_iterator       	reverse_iterator;
    typedef typename container_type::const_reverse_iterator  const_reverse_iterator;

	/////////////////////////////////////////////////////////////////////////// méthodes
	iterator 		begin() {
		return this->c.begin();
	};

	iterator		end() {
		return this->c.end();
	};

	const_iterator	begin() const {
		return this->c.begin();
	};

	const_iterator	end() const {
		return this->c.end();
	};

	reverse_iterator 		rbegin() {
		return this->c.rbegin();
	};

	reverse_iterator		rend() {
		return this->c.rend();
	};

	const_reverse_iterator	rbegin() const {
		return this->c.rbegin();
	};

	const_reverse_iterator	rend() const {
		return this->c.rend();
	};
	/////////////////////////////////////////////////////////////////////////// exceptions
};

#endif