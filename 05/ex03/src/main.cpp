/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:36:24 by mzimeris          #+#    #+#             */
/*   Updated: 2026/01/09 21:29:12 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
	std::cout << "=== TEST 1: Intern crée tous les formulaires ===" << std::endl;
	try {
		Intern someRandomIntern;
		Bureaucrat boss("Boss", 1);
		AForm* forms[3];
		
		forms[0] = someRandomIntern.makeForm("shrubbery creation", "Bender");
		forms[1] = someRandomIntern.makeForm("robotomy request", "Alice");
		forms[2] = someRandomIntern.makeForm("presidential pardon", "Arthur");
		
		std::cout << "\n--- Signature et exécution des formulaires ---" << std::endl;
		for (int i = 0; i < 3; i++) {
			if (forms[i]) {
				std::cout << *forms[i] << std::endl;
				boss.signForm(*forms[i]);
				boss.executeForm(*forms[i]);
				delete forms[i];
				std::cout << std::endl;
			}
		}
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 2: Intern avec un formulaire inconnu ===" << std::endl;
	try {
		Intern intern;
		AForm* form = intern.makeForm("unknown form", "target");
		
		if (form == NULL) {
			std::cout << "Le formulaire n'a pas été créé (NULL retourné)" << std::endl;
		} else {
			delete form;
		}
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}