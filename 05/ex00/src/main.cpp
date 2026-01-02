/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:36:24 by mzimeris          #+#    #+#             */
/*   Updated: 2026/01/02 15:52:57 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	try {
		std::cout << "Creating Bureaucrat with valid grade 1..." << std::endl;
		Bureaucrat bob("Bob", 1);
		std::cout << "\t" << bob << std::endl;
		std::cout << "Incrementing Bob's grade should throw an exception..." << std::endl;
		bob.incrementGrade();
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "\nCreating Bureaucrat with valid grade 150..." << std::endl;
		Bureaucrat alice("Alice", 150);
		std::cout << alice << std::endl;
		std::cout << "Decrementing Alice's grade should throw an exception..." << std::endl;
		alice.decrementGrade();
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "\nCreating Bureaucrat with invalid low grade 151..." << std::endl;
		Bureaucrat invalid("Invalid", 151);
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "\nCreating Bureaucrat with invalid high grade 0..." << std::endl;
		Bureaucrat invalid2("Invalid2", 0);
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}