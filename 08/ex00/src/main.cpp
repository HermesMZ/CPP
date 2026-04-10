/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 00:46:34 by zoum              #+#    #+#             */
/*   Updated: 2026/04/10 17:01:24 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include "test.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main() {
	std::cout << "\n=== Testing const and non-const containers ===" << std::endl;
	const int vecValues[] = {1, 2, 3, 4, 5};
	runEasyfindTests< std::vector<int> >("std::vector", vecValues,
		sizeof(vecValues) / sizeof(vecValues[0]), 3, 42);

	const int listValues[] = {10, 20, 30, 40, 50};
	runEasyfindTests< std::list<int> >("std::list", listValues,
		sizeof(listValues) / sizeof(listValues[0]), 30, 100);

	const int dequeValues[] = {100, 200, 300};
	runEasyfindTests< std::deque<int> >("std::deque", dequeValues,
		sizeof(dequeValues) / sizeof(dequeValues[0]), 200, 1);

	

	std::cout << "\n=== Testing with empty container ===" << std::endl;
	{
		std::vector<int> empty;
		printContainer(empty);
		testEasyfind(empty, 1);
	}

	return 0;
}
