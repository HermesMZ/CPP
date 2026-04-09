/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 00:15:25 by zoum              #+#    #+#             */
/*   Updated: 2026/04/09 18:31:44 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <cstddef>
# include <iostream>

template <typename T>
class Array {
private:
	T*				elements;
	unsigned int	_size;

public:
	Array() : elements(NULL), _size(0) {}
	Array(unsigned int n) : elements(new T[n]()), _size(n) {}
	
	Array(const Array& other) : elements(NULL), _size(0) {
		*this = other;
	}
	
	Array& operator=(const Array& other) {
		if (this != &other) {
			if (elements)
				delete[] elements;
			_size = other._size;
			if (_size > 0) {
				elements = new T[_size];
				for (unsigned int i = 0; i < _size; i++) {
					elements[i] = other.elements[i];
				}
			} else {
				elements = NULL;
			}
		}
		return *this;
	}

	~Array() {
		if (elements)
			delete[] elements;
	}

	T& operator[](unsigned int index) {
		if (index >= _size)
			throw std::exception();
		return elements[index];
	}

	const T& operator[](unsigned int index) const {
		if (index >= _size)
			throw std::exception();
		return elements[index];
	}

	unsigned int size() const {
		return _size;
	}

};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& array) {
	for (unsigned int i = 0; i < array.size(); i++) {
		os << array[i] << " ";
	}
	return os;
}
#endif
