/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:17:29 by mzimeris          #+#    #+#             */
/*   Updated: 2025/10/16 17:43:52 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

// ************************************************************************** //
//                               Zombie Class                                   //
// ************************************************************************** //

class Zombie
{
private:
	std::string name;
public:
	Zombie();
	~Zombie();

	void setName(std::string name);
	void announce( void );
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);


#endif // ZOMBIE_HPP