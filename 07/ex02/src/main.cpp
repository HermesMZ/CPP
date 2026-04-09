#include "Array.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#define MAX_VAL 750

int main(int, char**)
{
	std::cout << "=== Test 1: Empty array ===" << std::endl;
	{
		Array<int> empty;
		std::cout << "Empty array size: " << empty.size() << std::endl;
		try {
			empty[0] = 42;
			std::cout << "Error: should have thrown exception" << std::endl;
		} catch (std::exception& e) {
			std::cout << "Exception caught correctly for empty array" << std::endl;
		}
	}

	std::cout << "\n=== Test 2: Array with size ===" << std::endl;
	{
		Array<int> numbers(5);
		std::cout << "Array size: " << numbers.size() << std::endl;
		
		for (unsigned int i = 0; i < numbers.size(); i++) {
			numbers[i] = i * 10;
		}
		
		std::cout << "Array elements: ";
		for (unsigned int i = 0; i < numbers.size(); i++) {
			std::cout << numbers[i] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "\n=== Test 3: Copy constructor ===" << std::endl;
	{
		Array<int> original(3);
		original[0] = 100;
		original[1] = 200;
		original[2] = 300;
		
		Array<int> copy(original);
		std::cout << "Original array: ";
		for (unsigned int i = 0; i < original.size(); i++) {
			std::cout << original[i] << " ";
		}
		std::cout << std::endl;
		
		std::cout << "Copy array: ";
		for (unsigned int i = 0; i < copy.size(); i++) {
			std::cout << copy[i] << " ";
		}
		std::cout << std::endl;
		
		copy[0] = 999;
		std::cout << "After modifying copy[0] to 999:" << std::endl;
		std::cout << "Original[0]: " << original[0] << std::endl;
		std::cout << "Copy[0]: " << copy[0] << std::endl;
	}

	std::cout << "\n=== Test 4: Assignment operator ===" << std::endl;
	{
		Array<int> arr1(3);
		arr1[0] = 10;
		arr1[1] = 20;
		arr1[2] = 30;
		
		Array<int> arr2(2);
		arr2[0] = 1;
		arr2[1] = 2;
		
		std::cout << "Before assignment - arr2 size: " << arr2.size() << std::endl;
		arr2 = arr1;
		std::cout << "After assignment - arr2 size: " << arr2.size() << std::endl;
		
		std::cout << "arr2 elements: ";
		for (unsigned int i = 0; i < arr2.size(); i++) {
			std::cout << arr2[i] << " ";
		}
		std::cout << std::endl;
		
		arr2[1] = 999;
		std::cout << "After modifying arr2[1]:" << std::endl;
		std::cout << "arr1[1]: " << arr1[1] << std::endl;
		std::cout << "arr2[1]: " << arr2[1] << std::endl;
	}

	std::cout << "\n=== Test 5: Out of bounds exception ===" << std::endl;
	{
		Array<int> arr(5);
		try {
			arr[10] = 42;
			std::cout << "Error: should have thrown exception" << std::endl;
		} catch (std::exception& e) {
			std::cout << "Exception caught correctly for index 10" << std::endl;
		}
		
		try {
			int value = arr[5];
			(void)value;
			std::cout << "Error: should have thrown exception" << std::endl;
		} catch (std::exception& e) {
			std::cout << "Exception caught correctly for index 5" << std::endl;
		}
	}

	std::cout << "\n=== Test 6: String array ===" << std::endl;
	{
		Array<std::string> strings(3);
		strings[0] = "Hello";
		strings[1] = "World";
		strings[2] = "!";
		
		std::cout << "String array: ";
		for (unsigned int i = 0; i < strings.size(); i++) {
			std::cout << strings[i] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "\n=== Test 7: Large array test ===" << std::endl;
	{
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				delete[] mirror;
				return 1;
			}
		}
		
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cout << "Exception caught for negative index" << std::endl;
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cout << "Exception caught for index MAX_VAL" << std::endl;
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete[] mirror;
		std::cout << "Large array test passed!" << std::endl;
	}

	std::cout << "\n=== All tests completed successfully! ===" << std::endl;
	return 0;
}
