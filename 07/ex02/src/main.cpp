#include "Array.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <climits>

#define MAX_VAL 100000

int main(int, char**) {
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
		std::cout << numbers << std::endl;
	}

	std::cout << "\n=== Test 3: Copy constructor ===" << std::endl;
	{
		Array<int> original(3);
		original[0] = 100;
		original[1] = 200;
		original[2] = 300;
		
		Array<int> copy(original);
		std::cout << "Original array: ";
		std::cout << original << std::endl;
		
		std::cout << "Copy array: ";
		std::cout << copy << std::endl;
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

		std::cout << "arr1 elements: ";
		std::cout << arr1 << std::endl;
		std::cout << std::endl;

		std::cout << "arr2 elements: ";
		std::cout << arr2 << std::endl;
		std::cout << std::endl;
		
		std::cout << "Before assignment - arr2 size: " << arr2.size() << std::endl;
		arr2 = arr1;
		std::cout << "After assignment - arr2 size: " << arr2.size() << std::endl;
		
		std::cout << "arr2 elements: ";
		std::cout << arr2 << std::endl;
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
		std::cout << strings << std::endl;
	}

	std::cout << "\n=== Test 7: Large array test ===" << std::endl;
	{
		Array<int> numbers(MAX_VAL);
		srand(time(NULL));
		
		for (int i = 0; i < MAX_VAL; i++) {
			numbers[i] = rand();
		}
		
		Array<int> test(numbers);
		
		for (int i = 0; i < MAX_VAL; i++) {
			if (numbers[i] != test[i]) {
				std::cerr << "copy constructor failed" << std::endl;
				return 1;
			}
		}

		numbers[0] = numbers[0] + 1;
		if (numbers[0] == test[0]) {
			std::cerr << "copy is not independent" << std::endl;
			return 1;
		}

		std::cout << "Large array test passed!" << std::endl;
	}

	std::cout << "\n=== All tests completed successfully! ===" << std::endl;
	return 0;
}
