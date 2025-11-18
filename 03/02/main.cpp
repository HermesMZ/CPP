/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:51:15 by mzimeris          #+#    #+#             */
/*   Updated: 2025/11/18 15:32:56 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ScavTrap scav("scav");
	ClapTrap clap("clap");
	FragTrap frag("frag");

	scav.attack("Target1");
	scav.beRepaired(3);
	scav.beRepaired(3);
	scav.beRepaired(3);
	scav.beRepaired(3);
	scav.beRepaired(3);
	scav.beRepaired(3);
	scav.beRepaired(3);
	scav.beRepaired(3);
	scav.beRepaired(3);
	scav.takeDamage(10);
	scav.beRepaired(5);
	scav.takeDamage(100);
	
	scav.attack("Target2");
	return 0;
}