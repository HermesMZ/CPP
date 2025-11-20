/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:51:15 by mzimeris          #+#    #+#             */
/*   Updated: 2025/11/20 13:17:25 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::cout << "================== Battery of tests for ClapTrap / ScavTrap ==================" << std::endl;

	std::cout << "\n-- Constructors --" << std::endl;
	ClapTrap clap("clap");
	ScavTrap scav("scav");

	std::cout << "\n-- Copy / Assignment --" << std::endl;
	ClapTrap clap_copy(clap);
	ClapTrap clap_assigned("tmp");
	clap_assigned = clap;

	ScavTrap scav_copy(scav);
	ScavTrap scav_assigned("tmp2");
	scav_assigned = scav;

	std::cout << "\n-- Basic actions (attack / takeDamage / beRepaired) --" << std::endl;
	clap.attack("targetA");
	clap.takeDamage(3);
	clap.beRepaired(2);

	scav.attack("targetB");
	scav.takeDamage(10);
	scav.beRepaired(5);
	scav.guardGate();

	std::cout << "\n-- Edge cases: deplete energy then try to attack/repair --" << std::endl;
	// Deplete clap energy (initially 10)
	for (int i = 0; i < 11; ++i)
		clap.attack("drain");
	clap.beRepaired(1); // should not repair if energy is 0

	// Deplete scav energy
	for (int i = 0; i < 51; ++i)
		scav.attack("drain_scav");
	scav.beRepaired(1);

	std::cout << "\n-- Edge cases: destroy by damage then try actions --" << std::endl;
	ClapTrap frag("frag");
	frag.takeDamage(999); // bring to 0
	frag.attack("after_death");
	frag.beRepaired(5);

	ScavTrap frag2("frag2");
	frag2.takeDamage(200);
	frag2.attack("after_death2");
	frag2.beRepaired(10);

	std::cout << "\n-- Polymorphism tests --" << std::endl;
	// Call attack through base pointer to derived (to observe virtual vs non-virtual behavior)
	ClapTrap* poly = new ScavTrap("poly");
	std::cout << "Calling attack through ClapTrap* pointing to ScavTrap object:" << std::endl;
	poly->attack("poly_target");

	std::cout << "Deleting object via base pointer (safe because ClapTrap::~ClapTrap is virtual)." << std::endl;
	delete poly; // safe because destructor in base is virtual

	std::cout << "\n-- Dynamic allocation with explicit derived delete (also safe) --" << std::endl;
	ScavTrap* dyn = new ScavTrap("dyn");
	ClapTrap* as_base = dyn;
	as_base->attack("dyn_target");
	delete dyn; // deleted as derived pointer

	std::cout << "\nAll tests finished." << std::endl;
	std::cout << "Note: if you expect ScavTrap::attack to always be called through a ClapTrap* then make ClapTrap::attack virtual and mark ScavTrap::attack with override." << std::endl;
	return 0;
}