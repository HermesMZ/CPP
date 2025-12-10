/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:51:15 by mzimeris          #+#    #+#             */
/*   Updated: 2025/11/20 15:34:56 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

void printSeparator(std::string title) {
	std::cout << "\n==================== " << title << " ====================\n" << std::endl;
}

int main()
{
	printSeparator("TEST 1: Constructeur par défaut");
	{
		DiamondTrap diamond1;
		diamond1.whoAmI();
	}

	printSeparator("TEST 2: Constructeur avec paramètre");
	{
		DiamondTrap diamond2("Diamant");
		diamond2.whoAmI();
	}

	printSeparator("TEST 4: Méthode attack (héritée de ScavTrap)");
	{
		DiamondTrap attacker("Attacker");
		attacker.attack("Target");
		attacker.attack("Target");
	}

	printSeparator("TEST 5: Méthode takeDamage");
	{
		DiamondTrap defender("Defender");
		defender.takeDamage(30);
		defender.takeDamage(50);
		defender.takeDamage(30); // Devrait être mort
	}

	printSeparator("TEST 6: Méthode beRepaired");
	{
		DiamondTrap healer("Healer");
		healer.takeDamage(40);
		healer.beRepaired(20);
		healer.beRepaired(10);
	}

	printSeparator("TEST 7: Épuisement des points d'énergie");
	{
		DiamondTrap tired("Tired");
		// ScavTrap a 50 points d'énergie
		for (int i = 0; i < 52; i++) {
			tired.attack("Enemy");
		}
	}

	printSeparator("TEST 8: Actions après la mort");
	{
		DiamondTrap dead("Dead");
		dead.takeDamage(100);
		dead.attack("Someone");
		dead.beRepaired(50);
		dead.whoAmI();
	}

	printSeparator("TEST 9: Méthode guardGate (de ScavTrap)");
	{
		DiamondTrap guard("Guardian");
		guard.guardGate();
	}

	printSeparator("TEST 10: Méthode highFivesGuys (de FragTrap)");
	{
		DiamondTrap friendly("Friendly");
		friendly.highFivesGuys();
	}

	printSeparator("TEST 11: Constructeur de copie");
	{
		DiamondTrap original("Original");
		original.takeDamage(20);
		DiamondTrap copy(original);
		std::cout << "\nOriginal: ";
		original.whoAmI();
		std::cout << "Copy: ";
		copy.whoAmI();
	}

	printSeparator("TEST 12: Opérateur d'affectation");
	{
		DiamondTrap first("First");
		first.takeDamage(30);
		DiamondTrap second("Second");
		second = first;
		std::cout << "\nFirst: ";
		first.whoAmI();
		std::cout << "Second: ";
		second.whoAmI();
	}

	printSeparator("TEST 13: Combat complet");
	{
		DiamondTrap fighter1("Warrior");
		DiamondTrap fighter2("Knight");
		
		fighter1.whoAmI();
		fighter2.whoAmI();
		
		std::cout << "\n--- Round 1 ---" << std::endl;
		fighter1.attack("Knight");
		fighter2.takeDamage(30);
		
		std::cout << "\n--- Round 2 ---" << std::endl;
		fighter2.attack("Warrior");
		fighter1.takeDamage(30);
		
		std::cout << "\n--- Round 3 ---" << std::endl;
		fighter1.beRepaired(15);
		fighter2.beRepaired(15);
		
		std::cout << "\n--- Capacités spéciales ---" << std::endl;
		fighter1.guardGate();
		fighter2.highFivesGuys();
	}

	printSeparator("TEST 14: Multiple DiamondTraps");
	{
		DiamondTrap* army[3];
		army[0] = new DiamondTrap("Alpha");
		army[1] = new DiamondTrap("Beta");
		army[2] = new DiamondTrap("Gamma");
		
		for (int i = 0; i < 3; i++) {
			army[i]->whoAmI();
		}
		
		std::cout << "\nCleaning up army..." << std::endl;
		for (int i = 0; i < 3; i++) {
			delete army[i];
		}
	}

	printSeparator("TEST 15: Cas limites");
	{
		DiamondTrap edge("");
		edge.whoAmI();
		edge.attack("");
		edge.takeDamage(0);
		edge.beRepaired(0);
	}

	printSeparator("FIN DES TESTS");
	
	return 0;
}