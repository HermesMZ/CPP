/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:36:14 by mzimeris          #+#    #+#             */
/*   Updated: 2025/12/09 15:52:44 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default", 100, 100, 30) {
	std::cout << "FragTrap default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string const & name) : ClapTrap(name, 100, 100, 30) {
	std::cout << "FragTrap " << this->name << " constructed." << std::endl;
}

FragTrap::FragTrap(FragTrap const & other) : ClapTrap(other) {
	*this = other;
	std::cout << "FragTrap " << this->name << " copy constructed." <<  std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called." << std::endl;
}

void FragTrap::highFivesGuys(void) {
	if (this->hitPoints == 0) {
		std::cout << "FragTrap " << this->name << " cannot request a high five because he has no hit points left." << std::endl;
		return;
	}
	else if (this->energyPoints == 0) {
		std::cout << "FragTrap " << this->name << " cannot request a high five because he has no energy points left." << std::endl;
		return;
	}
	else
		std::cout << "FragTrap " << this->name << " is requesting a high five!" << std::endl;
}