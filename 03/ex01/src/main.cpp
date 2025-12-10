/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:51:15 by mzimeris          #+#    #+#             */
/*   Updated: 2025/11/20 14:50:07 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::cout << "================== Battery of tests for ScavTrap ==================" << std::endl;
	std::cout << std::endl;

	// Test 1: Default constructor
	std::cout << "--- Test 1: Default Constructor ---" << std::endl;
	ScavTrap scav1;
	std::cout << std::endl;

	// Test 2: Parameterized constructor
	std::cout << "--- Test 2: Parameterized Constructor ---" << std::endl;
	ScavTrap scav2("Guardian");
	std::cout << std::endl;

	// Test 3: Copy constructor
	std::cout << "--- Test 3: Copy Constructor ---" << std::endl;
	ScavTrap scav3(scav2);
	std::cout << std::endl;

	// Test 4: Assignment operator
	std::cout << "--- Test 4: Assignment Operator ---" << std::endl;
	ScavTrap scav4("Temporary");
	scav4 = scav2;
	std::cout << std::endl;

	// Test 5: Attack function (ScavTrap override)
	std::cout << "--- Test 5: Attack Function ---" << std::endl;
	scav2.attack("Enemy1");
	scav2.attack("Enemy2");
	scav2.attack("Enemy3");
	std::cout << std::endl;

	// Test 6: guardGate function (ScavTrap specific)
	std::cout << "--- Test 6: guardGate Function ---" << std::endl;
	scav2.guardGate();
	std::cout << std::endl;

	// Test 7: takeDamage function (inherited from ClapTrap)
	std::cout << "--- Test 7: takeDamage Function ---" << std::endl;
	scav2.takeDamage(30);
	scav2.takeDamage(40);
	std::cout << std::endl;

	// Test 8: beRepaired function (inherited from ClapTrap)
	std::cout << "--- Test 8: beRepaired Function ---" << std::endl;
	scav2.beRepaired(20);
	scav2.beRepaired(15);
	std::cout << std::endl;

	// Test 9: Energy depletion test
	std::cout << "--- Test 9: Energy Depletion Test ---" << std::endl;
	ScavTrap scav5("Energetic");
	for (int i = 0; i < 52; i++) {
		scav5.attack("Target");
	}
	std::cout << std::endl;

	// Test 10: No hit points test
	std::cout << "--- Test 10: No Hit Points Test ---" << std::endl;
	ScavTrap scav6("Doomed");
	scav6.takeDamage(100);
	scav6.attack("Ghost");
	scav6.beRepaired(10);
	scav6.guardGate();
	std::cout << std::endl;

	// Test 11: Repair after taking damage
	std::cout << "--- Test 11: Repair After Damage ---" << std::endl;
	ScavTrap scav7("Healer");
	scav7.attack("Enemy");
	scav7.takeDamage(50);
	scav7.beRepaired(25);
	scav7.attack("Enemy");
	std::cout << std::endl;

	// Test 12: Multiple guardGate calls
	std::cout << "--- Test 12: Multiple guardGate Calls ---" << std::endl;
	ScavTrap scav8("Gatekeeper");
	scav8.guardGate();
	scav8.guardGate();
	scav8.guardGate();
	std::cout << std::endl;

	// Test 13: Massive damage test
	std::cout << "--- Test 13: Massive Damage Test ---" << std::endl;
	ScavTrap scav9("Tank");
	scav9.takeDamage(150);
	std::cout << std::endl;

	// Test 14: Combination of actions
	std::cout << "--- Test 14: Combination of Actions ---" << std::endl;
	ScavTrap scav10("Warrior");
	scav10.attack("Orc");
	scav10.guardGate();
	scav10.takeDamage(25);
	scav10.beRepaired(10);
	scav10.attack("Goblin");
	scav10.guardGate();
	std::cout << std::endl;

	// Test 15: Polymorphism test
	std::cout << "--- Test 15: Polymorphism Test ---" << std::endl;
	ClapTrap* ptr = new ScavTrap("Polymorphic");
	ptr->attack("Virtual Enemy");
	delete ptr;
	std::cout << std::endl;

	std::cout << "--- Destructors called at end of scope ---" << std::endl;
	return 0;
}