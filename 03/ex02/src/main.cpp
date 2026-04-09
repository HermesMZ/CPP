/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:51:15 by mzimeris          #+#    #+#             */
/*   Updated: 2025/11/20 14:46:32 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

void printSeparator(std::string title) {
	std::cout << "\n==================== " << title << " ====================\n" << std::endl;
}

int main()
{
	// Test 1: Constructeur par défaut
	printSeparator("TEST 1: Constructeur par défaut");
	{
		FragTrap frag1;
		frag1.highFivesGuys();
	}

	// Test 2: Constructeur avec nom
	printSeparator("TEST 2: Constructeur avec nom");
	{
		FragTrap frag2("Fraggy");
		frag2.highFivesGuys();
	}

	// Test 3: Constructeur de copie
	printSeparator("TEST 3: Constructeur de copie");
	{
		FragTrap original("Original");
		FragTrap copy(original);
		std::cout << "\nTest des deux instances:" << std::endl;
		original.highFivesGuys();
		copy.highFivesGuys();
	}

	// Test 4: Opérateur d'assignation
	printSeparator("TEST 4: Opérateur d'assignation");
	{
		FragTrap frag1("FragOne");
		FragTrap frag2("FragTwo");
		std::cout << "\nAvant assignation:" << std::endl;
		frag1.highFivesGuys();
		frag2.highFivesGuys();
		
		frag2 = frag1;
		std::cout << "\nAprès assignation (frag2 = frag1):" << std::endl;
		frag1.highFivesGuys();
		frag2.highFivesGuys();
	}

	// Test 5: Attaques basiques
	printSeparator("TEST 5: Attaques basiques");
	{
		FragTrap attacker("Destroyer");
		attacker.attack("Target1");
		attacker.attack("Target2");
		attacker.attack("Target3");
	}

	// Test 6: Dégâts
	printSeparator("TEST 6: Prise de dégâts");
	{
		FragTrap tank("Tank");
		tank.takeDamage(30);
		tank.takeDamage(50);
		tank.takeDamage(15);
	}

	// Test 7: Réparations
	printSeparator("TEST 7: Réparations");
	{
		FragTrap healer("Healer");
		healer.takeDamage(40);
		healer.beRepaired(20);
		healer.beRepaired(30);
	}

	// Test 8: Épuisement de l'énergie
	printSeparator("TEST 8: Épuisement de l'énergie (100 actions)");
	{
		FragTrap energyTest("Energizer");
		std::cout << "Exécution de 100 attaques..." << std::endl;
		for (int i = 0; i < 100; i++) {
			energyTest.attack("Dummy");
		}
		std::cout << "\nTentative d'attaque après épuisement:" << std::endl;
		energyTest.attack("ShouldFail");
		std::cout << "\nTentative de réparation après épuisement:" << std::endl;
		energyTest.beRepaired(10);
	}

	// Test 9: Destruction complète (HP à 0)
	printSeparator("TEST 9: Destruction complète");
	{
		FragTrap destroyed("Doomed");
		destroyed.takeDamage(100);
		std::cout << "\nTentative d'actions après destruction:" << std::endl;
		destroyed.attack("CantAttack");
		destroyed.beRepaired(50);
		destroyed.highFivesGuys();
	}

	// Test 10: Overdamage
	printSeparator("TEST 10: Dégâts excessifs");
	{
		FragTrap overkill("Overkill");
		overkill.takeDamage(150); // Plus que ses HP
	}

	return 0;
}