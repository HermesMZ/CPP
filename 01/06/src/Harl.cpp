/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:00:12 by mzimeris          #+#    #+#             */
/*   Updated: 2025/10/22 14:31:47 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << "contextual informations" << std::endl;
}

void Harl::info( void )
{
	std::cout << "extensive informations" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "potential issue in the system" << std::endl;
}

void Harl::error( void )
{
	std::cout << "unrecoverable error has occurred" << std::endl;
}

void Harl::complain( std::string level )
{
	void	(Harl::*functions[])( void ) =
	{
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
			std::cout << "[ " << level << " ]" << std::endl;
			break ;
		}
		i++;
	}
	switch (i)
	{
		case 0:
			(this->*functions[0])();
		case 1:
			(this->*functions[1])();
		case 2:
			(this->*functions[2])();
		case 3:
		{
			(this->*functions[3])();
			break ;
		}
		default:
			std::cout << "No such level available." << std::endl;

	}
}