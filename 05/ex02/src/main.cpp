/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:36:24 by mzimeris          #+#    #+#             */
/*   Updated: 2026/01/09 21:05:56 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
	std::cout << "=== TEST 1: ShrubberyCreationForm ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 145);
		Bureaucrat executor("Executor", 137);
		ShrubberyCreationForm shrub("home");
		
		std::cout << bob << std::endl;
		std::cout << shrub << std::endl;
		
		bob.signForm(shrub);
		executor.executeForm(shrub);
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 2: RobotomyRequestForm ===" << std::endl;
	try {
		Bureaucrat alice("Alice", 40);
		RobotomyRequestForm robot("Bender");
		
		std::cout << alice << std::endl;
		std::cout << robot << std::endl;
		
		alice.signForm(robot);
		alice.executeForm(robot);
		alice.executeForm(robot);
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 3: PresidentialPardonForm ===" << std::endl;
	try {
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Arthur Dent");
		
		std::cout << president << std::endl;
		std::cout << pardon << std::endl;
		
		president.signForm(pardon);
		president.executeForm(pardon);
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 4: Execution sans signature ===" << std::endl;
	try {
		Bureaucrat john("John", 1);
		ShrubberyCreationForm shrub2("garden");
		
		std::cout << "Tentative d'exécution sans signature..." << std::endl;
		john.executeForm(shrub2);
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 5: Grade trop bas pour signer ===" << std::endl;
	try {
		Bureaucrat intern("Intern", 150);
		PresidentialPardonForm pardon2("Criminal");
		
		std::cout << intern << std::endl;
		intern.signForm(pardon2);
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 6: Grade trop bas pour exécuter ===" << std::endl;
	try {
		Bureaucrat boss("Boss", 5);
		Bureaucrat worker("Worker", 50);
		PresidentialPardonForm pardon3("Someone");
		
		boss.signForm(pardon3);
		std::cout << "Worker tente d'exécuter (grade trop bas)..." << std::endl;
		worker.executeForm(pardon3);
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}