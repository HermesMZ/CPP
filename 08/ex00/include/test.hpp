/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 00:46:34 by zoum              #+#    #+#             */
/*   Updated: 2026/04/10 17:05:34 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>
#include <string>
#include <cstddef>

template <typename Container>
void printContainer(const Container& container) {
	typename Container::const_iterator it = container.begin();
	typename Container::const_iterator end = container.end();

	std::cout << "Container: [";
	while (it != end) {
		std::cout << *it;
		++it;
		if (it != end)
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}

template <typename Container>
void testEasyfind(Container& container, int value) {
	try {
		typename Container::iterator it = easyfind(container, value);
		std::cout << "Found: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}

template <typename Container>
void testEasyfindConst(const Container& container, int value) {
	try {
		typename Container::const_iterator it = easyfind(container, value);
		std::cout << "Found: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}

template <typename Container>
Container makeContainer(const int* values, std::size_t size) {
	Container container;
	for (std::size_t i = 0; i < size; ++i)
		container.push_back(values[i]);
	return container;
}

template <typename Container>
void runEasyfindTests(const std::string& title, const int* values, std::size_t size,
	int presentValue, int missingValue) {
	std::cout << "\n=== Testing with " << title << " ===" << std::endl;
	Container container = makeContainer<Container>(values, size);
	printContainer(container);
	std::cout << "-- non-const --" << std::endl;
	testEasyfind(container, presentValue);
	testEasyfind(container, missingValue);
	std::cout << "-- const --" << std::endl;
	const Container constContainer = container;
	testEasyfindConst(constContainer, presentValue);
	testEasyfindConst(constContainer, missingValue);
}

#endif
