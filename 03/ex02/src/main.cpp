/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:51:15 by mzimeris          #+#    #+#             */
/*   Updated: 2025/12/08 16:19:04 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

void printSeparator(const std::string& title)
{
	std::cout << "\n========================================" << std::endl;
	std::cout << "  " << title << std::endl;
	std::cout << "========================================\n" << std::endl;
}

void testConstructorsAndBasics()
{
	printSeparator("TEST 1: CONSTRUCTEURS ET ACTIONS DE BASE");
	
	std::cout << "--- Constructeur avec nom ---" << std::endl;
	FragTrap robot("Robot42");
	
	std::cout << "\n--- Actions de base ---" << std::endl;
	robot.attack("Monster");
	robot.takeDamage(30);
	robot.beRepaired(15);
	
	std::cout << "\n--- Constructeur de copie ---" << std::endl;
	FragTrap copy(robot);
	copy.attack("Enemy");
}

void testHighFives()
{
	printSeparator("TEST 2: CAPACITÉ SPÉCIALE highFivesGuys()");
	
	FragTrap friendly("Friendly");
	friendly.highFivesGuys();
	friendly.attack("Target");
}

void testLimits()
{
	printSeparator("TEST 3: LIMITES (ÉNERGIE ET HP)");
	
	FragTrap fighter("Fighter");
	
	std::cout << "--- Épuisement de l'énergie (100 actions max) ---" << std::endl;
	for (int i = 1; i <= 101; i++)
		fighter.attack("Enemy");
	
	std::cout << "\n--- Mort par dégâts ---" << std::endl;
	FragTrap victim("Victim");
	victim.takeDamage(150);
	victim.attack("Ghost");
	victim.beRepaired(10);
}

int main()
{
	std::cout << "\n╔════════════════════════════════════════╗" << std::endl;
	std::cout << "║     TESTS FragTrap SIMPLIFIÉS         ║" << std::endl;
	std::cout << "╚════════════════════════════════════════╝\n" << std::endl;

	testConstructorsAndBasics();
	testHighFives();
	testLimits();

	std::cout << "\n╔════════════════════════════════════════╗" << std::endl;
	std::cout << "║      TOUS LES TESTS SONT TERMINÉS     ║" << std::endl;
	std::cout << "╚════════════════════════════════════════╝\n" << std::endl;

	return 0;
}