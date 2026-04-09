/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:10:01 by zoum              #+#    #+#             */
/*   Updated: 2026/01/14 17:10:02 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
	std::cout << "=== Basic test from subject ===" << std::endl;
	{
		Span sp = Span(5);
		
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << "\n=== Test with too many elements ===" << std::endl;
	{
		try {
			Span sp = Span(3);
			sp.addNumber(1);
			sp.addNumber(2);
			sp.addNumber(3);
			sp.addNumber(4); // Should throw
		} catch (const std::exception& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== Test with no span (only 1 element) ===" << std::endl;
	{
		try {
			Span sp = Span(1);
			sp.addNumber(42);
			std::cout << sp.shortestSpan() << std::endl; // Should throw
		} catch (const std::exception& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== Test with empty span ===" << std::endl;
	{
		try {
			Span sp = Span(10);
			std::cout << sp.longestSpan() << std::endl; // Should throw
		} catch (const std::exception& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== Test with 10,000 numbers ===" << std::endl;
	{
		Span sp = Span(10000);
		std::srand(std::time(0));

		for (int i = 0; i < 10000; i++)
		{
			sp.addNumber(std::rand());
		}

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n=== Test with range of iterators ===" << std::endl;
	{
		Span sp = Span(10);
		std::vector<int> vec;
		
		for (int i = 0; i < 10; i++)
			vec.push_back(i * 10);

		sp.addNumber(vec.begin(), vec.end());

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n=== Test range overflow ===" << std::endl;
	{
		try {
			Span sp = Span(5);
			std::vector<int> vec;
			
			for (int i = 0; i < 10; i++)
				vec.push_back(i);

			sp.addNumber(vec.begin(), vec.end()); // Should throw
		} catch (const std::exception& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== Test with negative numbers ===" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(-10);
		sp.addNumber(-5);
		sp.addNumber(0);
		sp.addNumber(5);
		sp.addNumber(10);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	return 0;
}
