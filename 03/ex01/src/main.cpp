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
#include "ScavTrap.hpp"

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
	ScavTrap robot("Robot42");
	
	std::cout << "\n--- Actions de base ---" << std::endl;
	robot.attack("Monster");
	robot.takeDamage(20);
	robot.beRepaired(10);
	
	std::cout << "\n--- Constructeur de copie ---" << std::endl;
	ScavTrap copy(robot);
	copy.attack("Enemy");
}

void testGuardGate()
{
	printSeparator("TEST 2: CAPACITÉ SPÉCIALE guardGate()");
	
	ScavTrap guard("Guardian");
	guard.guardGate();
	guard.attack("Intruder");
}

void testLimits()
{
	printSeparator("TEST 3: LIMITES (ÉNERGIE ET HP)");
	
	ScavTrap fighter("Fighter");
	
	std::cout << "--- Épuisement de l'énergie (50 actions max) ---" << std::endl;
	for (int i = 1; i <= 51; i++)
		fighter.attack("Enemy");
	
	std::cout << "\n--- Mort par dégâts ---" << std::endl;
	ScavTrap victim("Victim");
	victim.takeDamage(150);
	victim.attack("Ghost");
	victim.beRepaired(10);
}

int main()
{
	std::cout << "\n╔════════════════════════════════════════╗" << std::endl;
	std::cout << "║     TESTS ScavTrap SIMPLIFIÉS         ║" << std::endl;
	std::cout << "╚════════════════════════════════════════╝\n" << std::endl;

	testConstructorsAndBasics();
	testGuardGate();
	testLimits();

	std::cout << "\n╔════════════════════════════════════════╗" << std::endl;
	std::cout << "║      TOUS LES TESTS SONT TERMINÉS     ║" << std::endl;
	std::cout << "╚════════════════════════════════════════╝\n" << std::endl;

	return 0;
}