/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:36:24 by mzimeris          #+#    #+#             */
/*   Updated: 2026/01/02 16:30:30 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
	try {
		std::cout << "\tCreating Form with invalid high grade 0..." << std::endl;
		Form form2("form2", 0, 50);
		std::cout << form2 << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "\tCreating Form with invalid low grade 151..." << std::endl;
		Form form3("form3", 151, 50);
		std::cout << form3 << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n =================================================================\n" << std::endl;
	Bureaucrat john("John", 75);
	std::cout << john << std::endl;
	try {
		std::cout << "\tCreating Form with valid grades 1..." << std::endl;
		Form form1("form1", 1, 1);
		std::cout << form1 << std::endl;
		std::cout << "\tJohn attempts to sign the form..." << std::endl;
		john.signForm(form1);
		// john.signForm(const_cast<Form&>(form1));
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "\n\tCreating Form with valid grades 100..." << std::endl;
		Form form4("form4", 100, 50);
		std::cout << form4 << std::endl;
		std::cout << "\tJohn attempts to sign the form..." << std::endl;
		john.signForm(const_cast<Form&>(form4));
		std::cout << form4 << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}