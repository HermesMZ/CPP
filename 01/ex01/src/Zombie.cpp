/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:18:41 by mzimeris          #+#    #+#             */
/*   Updated: 2025/10/17 11:32:17 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "[DEBUG] Zombie " << this->name << " is created." << std::endl;
}


Zombie::~Zombie()
{
	std::cout << "[DEBUG] Zombie " << name << " is destroyed." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
std::string Zombie::getName() const
{
	return this->name;
}