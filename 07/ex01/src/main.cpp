/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 00:03:50 by zoum              #+#    #+#             */
/*   Updated: 2026/01/14 16:59:39 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void printElement(const T& element)
{
	std::cout << element << " ";
}

template <typename T>
void incrementElement(T& element)
{
	element++;
}

template <typename T>
void doubleElement(T& element)
{
	element *= 2;
}

void printString(const std::string& str)
{
	std::cout << str << " ";
}

void addExclamation(std::string& str)
{
	str += "!";
}

int main()
{
	std::cout << "=== Test 1: int array with print (const ref) ===" << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intLen = 5;
	
	std::cout << "Original: ";
	iter(intArray, intLen, printElement<int>);
	std::cout << std::endl;

	std::cout << "\n=== Test 2: int array with increment (non-const ref) ===" << std::endl;
	iter(intArray, intLen, incrementElement<int>);
	std::cout << "After increment: ";
	iter(intArray, intLen, printElement<int>);
	std::cout << std::endl;

	std::cout << "\n=== Test 3: int array with double (non-const ref) ===" << std::endl;
	iter(intArray, intLen, doubleElement<int>);
	std::cout << "After doubling: ";
	iter(intArray, intLen, printElement<int>);
	std::cout << std::endl;

	std::cout << "\n=== Test 4: const int array with print ===" << std::endl;
	const int constIntArray[] = {10, 20, 30, 40, 50};
	iter(constIntArray, 5, printElement<int>);
	std::cout << std::endl;

	std::cout << "\n=== Test 5: double array ===" << std::endl;
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::cout << "Original: ";
	iter(doubleArray, 5, printElement<double>);
	std::cout << std::endl;
	
	iter(doubleArray, 5, doubleElement<double>);
	std::cout << "After doubling: ";
	iter(doubleArray, 5, printElement<double>);
	std::cout << std::endl;

	std::cout << "\n=== Test 6: char array ===" << std::endl;
	char charArray[] = {'a', 'b', 'c', 'd', 'e'};
	std::cout << "Original: ";
	iter(charArray, 5, printElement<char>);
	std::cout << std::endl;
	
	iter(charArray, 5, incrementElement<char>);
	std::cout << "After increment: ";
	iter(charArray, 5, printElement<char>);
	std::cout << std::endl;

	std::cout << "\n=== Test 7: string array with const function ===" << std::endl;
	std::string stringArray[] = {"Hello", "World", "Test", "Array"};
	iter(stringArray, 4, printString);
	std::cout << std::endl;

	std::cout << "\n=== Test 8: string array with non-const function ===" << std::endl;
	iter(stringArray, 4, addExclamation);
	std::cout << "After adding exclamation: ";
	iter(stringArray, 4, printString);
	std::cout << std::endl;

	std::cout << "\n=== Test 9: const string array ===" << std::endl;
	const std::string constStringArray[] = {"Const", "String", "Array"};
	iter(constStringArray, 3, printString);
	// iter(constStringArray, 3, addExclamation); // doesn't compile
	std::cout << std::endl;

	return 0;
}
