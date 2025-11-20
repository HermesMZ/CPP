/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:05:16 by mzimeris          #+#    #+#             */
/*   Updated: 2025/11/20 11:41:25 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string const & name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << this->name << " constructed." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & other) : ClapTrap(other)
{
	std::cout << "ScavTrap " << this->name << " copy constructed." << std::endl;
	*this = other;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " destructed." << std::endl;
}

void ScavTrap::attack(const std::string & target)
{
	if (this->hitPoints == 0)
	{
		std::cout << "ScavTrap " << this->name << " has no hit points left and cannot attack as he is not a zombie." << std::endl;
		return;
	}
	if (this->energyPoints == 0)
	{
		std::cout << "ScavTrap " << this->name << " has no energy points left and cannot attack." << std::endl;
		return;
	}
	this->energyPoints--;
	std::cout << "ScavTrap " << this->name << " attacks " << target
			  << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}