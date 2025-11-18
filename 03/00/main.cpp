/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:51:15 by mzimeris          #+#    #+#             */
/*   Updated: 2025/11/18 13:59:44 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap("Clap");

	clap.attack("Target1");
	clap.beRepaired(3);
	clap.beRepaired(3);
	clap.beRepaired(3);
	clap.beRepaired(3);
	clap.beRepaired(3);
	clap.beRepaired(3);
	clap.beRepaired(3);
	clap.beRepaired(3);
	clap.beRepaired(3);
	clap.beRepaired(3);
	clap.beRepaired(3);
	clap.beRepaired(3);
	clap.beRepaired(3);
	clap.beRepaired(3);
	clap.beRepaired(3);
	clap.beRepaired(3);
	clap.takeDamage(10);
	clap.beRepaired(5);
	clap.takeDamage(100);
	
	clap.attack("Target2");
	return 0;
}