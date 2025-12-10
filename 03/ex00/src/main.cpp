/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:51:15 by mzimeris          #+#    #+#             */
/*   Updated: 2025/11/20 14:54:57 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void printSeparator(const std::string& title)
{
	std::cout << "\n========================================" << std::endl;
	std::cout << "  " << title << std::endl;
	std::cout << "========================================\n" << std::endl;
}

void testConstructors()
{
	printSeparator("TEST 1: CONSTRUCTEURS");
	
	std::cout << "--- Constructeur par défaut ---" << std::endl;
	ClapTrap ct1;
	
	std::cout << "\n--- Constructeur avec nom ---" << std::endl;
	ClapTrap ct2("Robot42");
	
	std::cout << "\n--- Constructeur de copie ---" << std::endl;
	ClapTrap ct3(ct2);
	
	std::cout << "\n--- Opérateur d'affectation ---" << std::endl;
	ClapTrap ct4;
	ct4 = ct2;
	
	std::cout << "\n--- Destructeurs (à la fin du scope) ---" << std::endl;
}

void testBasicAttack()
{
	printSeparator("TEST 2: ATTAQUE DE BASE");
	
	ClapTrap hero("Hero");
	hero.attack("Monster");
	hero.attack("Dragon");
	hero.attack("Goblin");
}

void testEnergyDepletion()
{
	printSeparator("TEST 3: ÉPUISEMENT DE L'ÉNERGIE");
	
	ClapTrap fighter("Fighter");
	
	std::cout << "--- Attaques jusqu'à épuisement de l'énergie (10 actions max) ---" << std::endl;
	for (int i = 1; i <= 12; i++)
	{
		fighter.attack("Enemy");
	}
}

void testRepair()
{
	printSeparator("TEST 4: RÉPARATION");
	
	ClapTrap mechanic("Mechanic");
	
	std::cout << "--- Réparations normales ---" << std::endl;
	mechanic.beRepaired(5);
	mechanic.beRepaired(3);
	mechanic.beRepaired(2);
}

void testDamage()
{
	printSeparator("TEST 5: DÉGÂTS");
	
	ClapTrap victim("Victim");
	
	std::cout << "--- Prendre des dégâts (HP initial: 10) ---" << std::endl;
	victim.takeDamage(3);
	victim.takeDamage(2);
	victim.takeDamage(4);
	
	std::cout << "\n--- Tentative d'attaque après avoir pris des dégâts ---" << std::endl;
	victim.attack("Enemy");
}

void testDeath()
{
	printSeparator("TEST 6: MORT DU CLAPTRAP");
	
	ClapTrap doomed("Doomed");
	
	std::cout << "--- Dégâts fatals (plus que les HP) ---" << std::endl;
	doomed.takeDamage(15);
	
	std::cout << "\n--- Tentatives d'actions après la mort ---" << std::endl;
	doomed.attack("Ghost");
	doomed.beRepaired(10);
	
	std::cout << "\n--- Dégâts supplémentaires sur un ClapTrap mort ---" << std::endl;
	doomed.takeDamage(5);
}

void testEnergyDepletionWithRepair()
{
	printSeparator("TEST 7: ÉPUISEMENT D'ÉNERGIE AVEC RÉPARATIONS");
	
	ClapTrap worker("Worker");
	
	std::cout << "--- Mélange d'attaques et réparations ---" << std::endl;
	worker.attack("Target1");
	worker.beRepaired(2);
	worker.attack("Target2");
	worker.beRepaired(3);
	worker.attack("Target3");
	worker.beRepaired(1);
	worker.attack("Target4");
	worker.beRepaired(2);
	worker.attack("Target5");
	worker.beRepaired(1);
	
	std::cout << "\n--- Plus d'énergie ---" << std::endl;
	worker.attack("Target6");
	worker.beRepaired(5);
}

void testDamageAndRepair()
{
	printSeparator("TEST 8: DÉGÂTS ET RÉPARATIONS");
	
	ClapTrap survivor("Survivor");
	
	std::cout << "--- Combat avec réparations ---" << std::endl;
	survivor.attack("Enemy");
	survivor.takeDamage(5);
	survivor.beRepaired(3);
	survivor.takeDamage(4);
	survivor.beRepaired(2);
	survivor.attack("Enemy");
	survivor.takeDamage(8);
	survivor.beRepaired(1);
}

void testExtremeDamage()
{
	printSeparator("TEST 9: DÉGÂTS EXTRÊMES");
	
	ClapTrap tank("Tank");
	
	std::cout << "--- Dégâts massifs en une fois ---" << std::endl;
	tank.takeDamage(1000);
	
	std::cout << "\n--- Tentatives d'actions ---" << std::endl;
	tank.attack("Nothing");
	tank.beRepaired(100);
}

void testSequentialDeath()
{
	printSeparator("TEST 10: MORT PROGRESSIVE");
	
	ClapTrap gradual("Gradual");
	
	std::cout << "--- Dégâts progressifs jusqu'à la mort ---" << std::endl;
	gradual.takeDamage(3);
	gradual.attack("Enemy1");
	gradual.takeDamage(3);
	gradual.attack("Enemy2");
	gradual.takeDamage(3);
	gradual.attack("Enemy3");
	gradual.takeDamage(3);
	
	std::cout << "\n--- Tentative d'action après la mort ---" << std::endl;
	gradual.attack("Enemy4");
}

void testMixedScenario()
{
	printSeparator("TEST 11: SCÉNARIO MIXTE COMPLEXE");
	
	ClapTrap complex("Complex");
	
	std::cout << "--- Scénario de combat réaliste ---" << std::endl;
	complex.attack("Orc");
	complex.takeDamage(2);
	complex.beRepaired(1);
	complex.attack("Orc");
	complex.takeDamage(3);
	complex.beRepaired(2);
	complex.attack("Troll");
	complex.takeDamage(5);
	complex.beRepaired(3);
	complex.attack("Troll");
	complex.takeDamage(8);
	
	std::cout << "\n--- ClapTrap affaibli mais vivant ---" << std::endl;
	complex.attack("LastEnemy");
}

void testCopyBehavior()
{
	printSeparator("TEST 12: COMPORTEMENT DES COPIES");
	
	ClapTrap original("Original");
	
	std::cout << "--- Actions sur l'original ---" << std::endl;
	original.attack("Target1");
	original.takeDamage(5);
	
	std::cout << "\n--- Création d'une copie ---" << std::endl;
	ClapTrap copy(original);
	
	std::cout << "\n--- Actions sur la copie ---" << std::endl;
	copy.attack("Target2");
	copy.beRepaired(2);
	
	std::cout << "\n--- Actions sur l'original (doit être indépendant) ---" << std::endl;
	original.attack("Target3");
}

int main()
{
	std::cout << "\n╔════════════════════════════════════════╗" << std::endl;
	std::cout << "║  BATTERIE DE TESTS CLAPTRAP COMPLÈTE  ║" << std::endl;
	std::cout << "╚════════════════════════════════════════╝\n" << std::endl;

	testConstructors();
	testBasicAttack();
	testEnergyDepletion();
	testRepair();
	testDamage();
	testDeath();
	testEnergyDepletionWithRepair();
	testDamageAndRepair();
	testExtremeDamage();
	testSequentialDeath();
	testMixedScenario();
	testCopyBehavior();

	std::cout << "\n╔════════════════════════════════════════╗" << std::endl;
	std::cout << "║      TOUS LES TESTS SONT TERMINÉS     ║" << std::endl;
	std::cout << "╚════════════════════════════════════════╝\n" << std::endl;

	return 0;
}