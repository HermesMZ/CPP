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

#include "ClapTrap.hpp"

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
	ClapTrap robot("Robot42");
	
	std::cout << "\n--- Actions de base ---" << std::endl;
	robot.attack("Monster");
	robot.takeDamage(3);
	robot.beRepaired(2);
	
	std::cout << "\n--- Constructeur de copie ---" << std::endl;
	ClapTrap copy(robot);
	copy.attack("Enemy");
}

void testLimits()
{
	printSeparator("TEST 2: LIMITES (ÉNERGIE ET HP)");
	
	ClapTrap fighter("Fighter");
	
	std::cout << "--- Épuisement de l'énergie (10 actions max) ---" << std::endl;
	for (int i = 1; i <= 11; i++)
		fighter.attack("Enemy");
	
	std::cout << "\n--- Mort par dégâts ---" << std::endl;
	ClapTrap victim("Victim");
	victim.takeDamage(15);
	victim.attack("Ghost");
	victim.beRepaired(10);
}

int main()
{
	std::cout << "\n╔════════════════════════════════════════╗" << std::endl;
	std::cout << "║     TESTS ClapTrap SIMPLIFIÉS         ║" << std::endl;
	std::cout << "╚════════════════════════════════════════╝\n" << std::endl;

	testConstructorsAndBasics();
	testLimits();

	std::cout << "\n╔════════════════════════════════════════╗" << std::endl;
	std::cout << "║      TOUS LES TESTS SONT TERMINÉS     ║" << std::endl;
	std::cout << "╚════════════════════════════════════════╝\n" << std::endl;

	return 0;
}