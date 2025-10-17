/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:00:12 by mzimeris          #+#    #+#             */
/*   Updated: 2025/10/17 17:26:15 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << "[DEBUG]   contextual informations" << std::endl;
}

void Harl::info( void )
{
	std::cout << "[INFO]    extensive informations" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[WARNING] potential issue in the system" << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ERROR]   unrecoverable error has occurred" << std::endl;
}

void Harl::complain( std::string level )
{
	void	(Harl::*functions[])( void ) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	int i = 0;
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	while (i < 4)
	{
		if (levels[i] == level)
		{
			(this->*functions[i])();
			return;
		}
		i++;
	}
	std::cout << "[UNKNOWN] unrecognized level" << std::endl;
}