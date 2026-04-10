/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 17:58:00 by zoum              #+#    #+#             */
/*   Updated: 2026/04/10 18:02:07 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
#define TEST_HPP

#include "Span.hpp"
#include <iostream>
#include <string>
#include <cstddef>

void printSpan(const std::string& label, int shortest, int longest) {
	std::cout << label << " - Shortest: " << shortest << ", Longest: " << longest << std::endl;
}

void printSpanError(const std::string& context) {
	std::cout << "[Error] " << context << std::endl;
}

void printNumbers(const Span& span) {
	const std::vector<int>& numbers = span.getNumbers();
	std::cout << "Numbers: [";
	for (std::size_t i = 0; i < numbers.size(); ++i) {
		std::cout << numbers[i];
		if (i < numbers.size() - 1)
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}

template <typename Span>
void addNumbersFromArray(Span& span, const int* values, std::size_t size) {
	for (std::size_t i = 0; i < size; ++i) {
		span.addNumber(values[i]);
	}
}

void runBasicTest() {
	std::cout << "\n=== Basic test from subject ===" << std::endl;
	
	try {
		Span sp = Span(5);
		const int values[] = {6, 3, 17, 9, 11};
		addNumbersFromArray(sp, values, 5);
		printNumbers(sp);
		printSpan("Result", sp.shortestSpan(), sp.longestSpan());
	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void runTooManyElementsTest() {
	std::cout << "\n=== Test with too many elements ===" << std::endl;
	try {
		Span sp = Span(3);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		printNumbers(sp);
		sp.addNumber(4);
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void runSingleElementTest() {
	std::cout << "\n=== Test with no span (only 1 element) ===" << std::endl;
	try {
		Span sp = Span(1);
		sp.addNumber(42);
		printNumbers(sp);
		std::cout << sp.shortestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void runEmptySpanTest() {
	std::cout << "\n=== Test with empty span ===" << std::endl;
	try {
		Span sp = Span(10);
		std::cout << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void runNegativeNumbersTest() {
	std::cout << "\n=== Test with negative numbers ===" << std::endl;
	try {
		Span sp = Span(5);
		const int values[] = {-10, -5, 0, 5, 10};
		addNumbersFromArray(sp, values, 5);
		printNumbers(sp);
		printSpan("Result", sp.shortestSpan(), sp.longestSpan());
	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void runIdenticalNumbersTest() {
	std::cout << "\n=== Test with identical numbers ===" << std::endl;
	try {
		Span sp = Span(5);
		sp.addNumber(42);
		sp.addNumber(42);
		sp.addNumber(42);
		printNumbers(sp);
		printSpan("Result", sp.shortestSpan(), sp.longestSpan());
	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void runAscendingProgressionTest() {
	std::cout << "\n=== Test with ascending progression ===" << std::endl;
	try {
		Span sp = Span(10);
		for (int i = 0; i < 10; i++)
			sp.addNumber(i);
		printNumbers(sp);
		printSpan("Result", sp.shortestSpan(), sp.longestSpan());
	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void runDescendingProgressionTest() {
	std::cout << "\n=== Test with descending progression ===" << std::endl;
	try {
		Span sp = Span(10);
		for (int i = 90; i >= 0; i -= 10)
			sp.addNumber(i);
		printNumbers(sp);
		printSpan("Result", sp.shortestSpan(), sp.longestSpan());
	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

template <typename Container>
void runIteratorTest(const std::string& containerType, typename Container::iterator begin, typename Container::iterator end) {
	std::cout << "\n=== Test with " << containerType << " iterator ===" << std::endl;
	try {
		Span sp = Span(10);
		sp.addNumber(begin, end);
		printSpan("Result", sp.shortestSpan(), sp.longestSpan());
	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void runCopyConstructorTest() {
	std::cout << "\n=== Test copy constructor and mutation ===" << std::endl;
	try {
		Span sp1 = Span(5);
		sp1.addNumber(1);
		sp1.addNumber(2);
		sp1.addNumber(3);

		Span sp2 = sp1;
		sp2.addNumber(100);
		sp2.addNumber(200);

		std::cout << "Original: " << sp1.shortestSpan() << " / " << sp1.longestSpan() << std::endl;
		std::cout << "Modified: " << sp2.shortestSpan() << " / " << sp2.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void runAssignmentOperatorTest() {
	std::cout << "\n=== Test operator= and mutation ===" << std::endl;
	try {
		Span sp1 = Span(5);
		sp1.addNumber(10);
		sp1.addNumber(20);

		Span sp2 = Span(10);
		sp2.addNumber(5);
		sp2 = sp1;
		sp2.addNumber(30);

		std::cout << "Original: " << sp1.shortestSpan() << " / " << sp1.longestSpan() << std::endl;
		std::cout << "Assigned: " << sp2.shortestSpan() << " / " << sp2.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

#endif
