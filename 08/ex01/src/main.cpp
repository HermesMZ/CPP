/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:10:01 by zoum              #+#    #+#             */
/*   Updated: 2026/04/10 18:05:48 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "test.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <list>
#include <deque>
#include <climits>
#include <vector>

int main() {
	runBasicTest();
	runTooManyElementsTest();
	runSingleElementTest();
	runEmptySpanTest();

	std::cout << "\n=== Test with 10,000 numbers ===" << std::endl;
	{
		Span sp = Span(10000);
		std::srand(std::time(0));
		for (int i = 0; i < 10000; i++) {
			sp.addNumber(std::rand());
		}
		printSpan("Result", sp.shortestSpan(), sp.longestSpan());
	}

	std::cout << "\n=== Test with 10,000,000 numbers ===" << std::endl;
	{
		Span sp = Span(10000000);
		std::srand(std::time(0));
		for (int i = 0; i < 10000000; i++) {
			sp.addNumber(std::rand());
		}
		printSpan("Result", sp.shortestSpan(), sp.longestSpan());
	}

	std::cout << "\n=== Test with range of iterators (vector) ===" << std::endl;
	{
		Span sp = Span(10);
		std::vector<int> vec;
		for (int i = 0; i < 10; i++)
			vec.push_back(i * 10);
		sp.addNumber(vec.begin(), vec.end());
		printNumbers(sp);
		printSpan("Result", sp.shortestSpan(), sp.longestSpan());
	}

	std::cout << "\n=== Test range overflow ===" << std::endl;
	{
		try {
			Span sp = Span(5);
			std::vector<int> vec;
			for (int i = 0; i < 10; i++)
				vec.push_back(i);
			std::cout << "Vector to add: ";
			for (int i = 0; i < 10; i++)
				std::cout << i << (i < 9 ? ", " : "");
			std::cout << std::endl;
			sp.addNumber(vec.begin(), vec.end());
		} catch (const std::exception& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}

	runNegativeNumbersTest();
	runIdenticalNumbersTest();

	std::cout << "\n=== Test with INT_MAX and INT_MIN ===" << std::endl;
	{
		try {
			Span sp = Span(5);
			sp.addNumber(INT_MAX);
			sp.addNumber(INT_MIN);
			sp.addNumber(0);
			printNumbers(sp);
			printSpan("Result", sp.shortestSpan(), sp.longestSpan());
		} catch (const std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== Test with N=1 (edge case) ===" << std::endl;
	{
		try {
			Span sp = Span(1);
			sp.addNumber(123);
			std::cout << "Added one number" << std::endl;
			sp.addNumber(456);
		} catch (const std::exception& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== Test with 100,000 numbers ===" << std::endl;
	{
		Span sp = Span(100000);
		std::srand(std::time(0));
		for (int i = 0; i < 100000; i++) {
			sp.addNumber(std::rand());
		}
		printSpan("Result", sp.shortestSpan(), sp.longestSpan());
	}

	runAscendingProgressionTest();
	runDescendingProgressionTest();
	runCopyConstructorTest();
	runAssignmentOperatorTest();

	std::cout << "\n=== Test with std::list iterator ===" << std::endl;
	{
		Span sp = Span(10);
		std::list<int> lst;
		for (int i = 0; i < 10; i++) {
			lst.push_back(i * 5);
		}
		sp.addNumber(lst.begin(), lst.end());
		printNumbers(sp);
		printSpan("Result", sp.shortestSpan(), sp.longestSpan());
	}

	std::cout << "\n=== Test with std::deque iterator ===" << std::endl;
	{
		Span sp = Span(8);
		std::deque<int> dq;
		for (int i = 0; i < 8; i++) {
			dq.push_back(i * 15);
		}
		sp.addNumber(dq.begin(), dq.end());
		printNumbers(sp);
		printSpan("Result", sp.shortestSpan(), sp.longestSpan());
	}

	std::cout << "\n=== Test addNumber() with empty range ===" << std::endl;
	{
		Span sp = Span(10);
		sp.addNumber(42);
		sp.addNumber(100);
		std::vector<int> empty_vec;
		sp.addNumber(empty_vec.begin(), empty_vec.end());
		printNumbers(sp);
		std::cout << "After adding empty range, shortest span: " << sp.shortestSpan() << std::endl;
	}

	return 0;
}
