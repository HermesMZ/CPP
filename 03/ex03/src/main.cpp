/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:51:15 by mzimeris          #+#    #+#             */
/*   Updated: 2025/12/08 16:16:52 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
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
	DiamondTrap robot("Robot42");
	
	std::cout << "\n--- Actions de base ---" << std::endl;
	robot.attack("Monster");
	robot.takeDamage(20);
	robot.beRepaired(10);
	
	std::cout << "\n--- Constructeur de copie ---" << std::endl;
	DiamondTrap copy(robot);
	copy.attack("Enemy");
}

void testSpecialAbilities()
{
	printSeparator("TEST 2: CAPACITÉS SPÉCIALES");
	
	DiamondTrap hero("Hero");
	
	std::cout << "--- guardGate() de ScavTrap ---" << std::endl;
	hero.guardGate();
	
	std::cout << "\n--- highFivesGuys() de FragTrap ---" << std::endl;
	hero.highFivesGuys();
	
	std::cout << "\n--- whoAmI() de DiamondTrap ---" << std::endl;
	hero.whoAmI();
}

void testLimits()
{
	printSeparator("TEST 3: LIMITES (ÉNERGIE ET HP)");
	
	DiamondTrap fighter("Fighter");
	
	std::cout << "--- Épuisement de l'énergie ---" << std::endl;
	for (int i = 1; i <= 51; i++)
		fighter.attack("Enemy");
	
	std::cout << "\n--- Mort par dégâts ---" << std::endl;
	DiamondTrap victim("Victim");
	victim.takeDamage(150);
	victim.attack("Ghost");
	victim.beRepaired(10);
}

int main()
{
	std::cout << "\n╔════════════════════════════════════════╗" << std::endl;
	std::cout << "║     TESTS DiamondTrap SIMPLIFIÉS      ║" << std::endl;
	std::cout << "╚════════════════════════════════════════╝\n" << std::endl;

	testConstructorsAndBasics();
	testSpecialAbilities();
	testLimits();

	std::cout << "\n╔════════════════════════════════════════╗" << std::endl;
	std::cout << "║      TOUS LES TESTS SONT TERMINÉS     ║" << std::endl;
	std::cout << "╚════════════════════════════════════════╝\n" << std::endl;

	return 0;
}