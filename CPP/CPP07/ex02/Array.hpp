#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <iostream>
#include <stdexcept>

template<typename T>
class Array {
private:
	/////////////////////////////////////////////////////////////////////////// attributs
	T* _data;
	unsigned int _size;
public:
	/////////////////////////////////////////////////////////////////////////// constructeur
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	~Array();

	/////////////////////////////////////////////////////////////////////////// opérateurs
	Array& operator=(const Array& other);
	T& operator[](unsigned int index);
	const T& operator[](unsigned int index) const;

	/////////////////////////////////////////////////////////////////////////// getter / setter
	unsigned int size() const;
};

/////////////////////////////////////////////////////////////////////////// corp de la class
template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {
	std::cout << "Default constructor\n";
}

template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n) {
	std::cout << "Int constructor\n";
}

template <typename T>
Array<T>::Array(const Array& other) : _data(NULL), _size(0) {
	std::cout << "Copy constructor\n";
	this->_size = other._size;
	this->_data = new T[_size]();
	for (unsigned int i = 0; i < _size; i++) {
		this->_data[i] = other._data[i];
	}
}

template <typename T>
Array<T>::~Array() {
	std::cout << "Destructor\n";
	delete []_data;
}

/////////////////////////////////////////////////////////////////////////// opérateur
template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this != &other) {
		std::cout << "= operator\n";
		delete []_data;
		this->_size = other._size;
		this->_data = new T[_size]();
		for (unsigned int i = 0; i < _size; i++) {
			this->_data[i] = other._data[i];
		}
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
	std::cout << "[] operator\n";
	if (index >= this->_size)
		throw std::out_of_range("Index out of bounds");
	return this->_data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
	std::cout << "const [] operator\n";
	if (index >= this->_size)
		throw std::out_of_range("Index out of bounds");
	return this->_data[index];
}

/////////////////////////////////////////////////////////////////////////// getter / setter
template <typename T>
unsigned int Array<T>::size() const {
	std::cout << "size getter\n";
	return this->_size;
}

#endif