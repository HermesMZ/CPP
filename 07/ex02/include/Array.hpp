/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 00:15:25 by zoum              #+#    #+#             */
/*   Updated: 2026/01/14 00:20:33 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <cstddef>

template <typename T>
class Array {
private:
	T*				elements;
	unsigned int	size;

public:
	Array() : elements(NULL), size(0) {}
	Array(unsigned int n) : elements(new T[n]()), size(n) {}
	
	Array(const Array& other) : elements(NULL), size(0) {
		*this = other;
	}
	
	Array& operator=(const Array& other) {
		if (this != &other) {
			if (elements)
				delete[] elements;
			size = other.size;
			if (size > 0) {
				elements = new T[size];
				for (unsigned int i = 0; i < size; i++) {
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
		if (index >= size)
			throw std::exception();
		return elements[index];
	}

	const T& operator[](unsigned int index) const {
		if (index >= size)
			throw std::exception();
		return elements[index];
	}

	unsigned int size() const {
		return size;
	}
};

#endif
