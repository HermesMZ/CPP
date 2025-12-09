/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:04:58 by mzimeris          #+#    #+#             */
/*   Updated: 2025/12/09 15:50:57 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

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