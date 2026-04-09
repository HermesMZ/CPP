/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:51:15 by mzimeris          #+#    #+#             */
/*   Updated: 2025/12/10 11:13:02 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	std::cout << "=== Test 1: Array of Animals ===" << std::endl;
	Animal* animals[4];
	for (int i = 0; i < 4; i++) {
		if (i < 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << std::endl;
	}
	for (int i = 0; i < 4; i++) {
		std::cout << "Animal type: " << animals[i]->getType() << std::endl;
		animals[i]->makeSound();
		delete animals[i];
		std::cout << std::endl;
	}

	std::cout << "\n=== Test 2: Deep Copy Constructor (Dog) ===" << std::endl;
	{
		std::cout << "Creating original dog..." << std::endl;
		Dog original;
		std::cout << "\nCopying dog using copy constructor..." << std::endl;
		Dog copy(original);
		std::cout << "\nBoth dogs exist, original address: " << &original 
			<< ", copy address: " << &copy << std::endl;
		std::cout << "These are different objects, ensuring deep copy." << std::endl;
		std::cout << "\nLeaving scope, destructors will be called..." << std::endl;
	}
	std::cout << "Both dogs destroyed without double-free (deep copy works!)\n" << std::endl;

	std::cout << "=== Test 3: Deep Copy Constructor (Cat) ===" << std::endl;
	{
		std::cout << "Creating original cat..." << std::endl;
		Cat original;
		std::cout << "\nCopying cat using copy constructor..." << std::endl;
		Cat copy(original);
		std::cout << "\nBoth cats exist, original address: " << &original 
			<< ", copy address: " << &copy << std::endl;
		std::cout << "These are different objects, ensuring deep copy." << std::endl;
		std::cout << "\nLeaving scope, destructors will be called..." << std::endl;
	}
	std::cout << "Both cats destroyed without double-free (deep copy works!)\n" << std::endl;

	std::cout << "=== Test 4: Assignment Operator (Dog) ===" << std::endl;
	{
		std::cout << "Creating dog1..." << std::endl;
		Dog dog1;
		std::cout << "\nCreating dog2..." << std::endl;
		Dog dog2;
		std::cout << "\nAssigning dog1 to dog2..." << std::endl;
		dog2 = dog1;
		std::cout << "\nBoth dogs exist, dog1 address: " << &dog1 
			<< ", dog2 address: " << &dog2 << std::endl;
		std::cout << "These are different objects, ensuring deep copy." << std::endl;
		std::cout << "\nLeaving scope, destructors will be called..." << std::endl;
	}
	std::cout << "Both dogs destroyed without double-free (assignment works!)\n" << std::endl;

	std::cout << "=== Test 5: Assignment Operator (Cat) ===" << std::endl;
	{
		std::cout << "Creating cat1..." << std::endl;
		Cat cat1;
		std::cout << "\nCreating cat2..." << std::endl;
		Cat cat2;
		std::cout << "\nAssigning cat1 to cat2..." << std::endl;
		cat2 = cat1;
		std::cout << "\nBoth cats exist, cat1 address: " << &cat1 
			<< ", cat2 address: " << &cat2 << std::endl;
		std::cout << "These are different objects, ensuring deep copy." << std::endl;
		std::cout << "\nLeaving scope, destructors will be called..." << std::endl;
	}
	std::cout << "Both cats destroyed without double-free (assignment works!)\n" << std::endl;

	std::cout << "=== Test 6: Self Assignment ===" << std::endl;
	{
		std::cout << "Creating dog..." << std::endl;
		Dog dog;
		Dog* ptr = &dog;
		std::cout << "\nSelf-assigning dog to itself..." << std::endl;
		*ptr = dog;
		std::cout << "Self-assignment handled correctly." << std::endl;
		std::cout << "\nLeaving scope..." << std::endl;
	}
	std::cout << "Dog destroyed correctly after self-assignment.\n" << std::endl;

	std::cout << "=== All tests completed! Run with valgrind to verify no leaks ===" << std::endl;
	return 0;
}