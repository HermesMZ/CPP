/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:04:58 by mzimeris          #+#    #+#             */
/*   Updated: 2025/11/20 14:26:11 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

//scavtrap herite de claptrap
class ScavTrap : public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(std::string const & name);
		ScavTrap(ScavTrap const & other);
		ScavTrap & operator=(ScavTrap const & other);
		~ScavTrap();
		void attack(const std::string & target);
		void guardGate();
};

#endif