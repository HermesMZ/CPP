/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:03:41 by mzimeris          #+#    #+#             */
/*   Updated: 2025/11/20 11:53:00 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap default constructor called for " << name << std::endl;
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " has no hit points left and cannot attack as he is not a zombie." << std::endl;
		return;
	}
	if (this->energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " has no energy points left and cannot attack." << std::endl;
		return;
	}
	this->energyPoints--;
	std::cout << "ClapTrap " << this->name << " attacks " << target
			  << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints < amount)
	{
		this->hitPoints = 0;
		this->energyPoints = 0;
		std::cout << this->name << " has taken " << amount << " damage points and has been destroyed!" << std::endl;
	}
	else
	{
		this->hitPoints -= amount;
		std::cout << this->name << " has taken " << amount << " damage points and has now " << this->hitPoints << " hit points left." << std::endl;		
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints == 0)
	{
		std::cout << this->name << " has no hit points left and cannot be repaired." << std::endl;
		return;
	}
	if (this->energyPoints == 0)
	{
		std::cout << this->name << " has no energy points left and cannot be repaired." << std::endl;
		return;
	}
	this->energyPoints--;
	this->hitPoints += amount;
	std::cout << this->name << " is repaired by " << amount
			  << " points and has now " << this->hitPoints << " hit points." << std::endl;
}