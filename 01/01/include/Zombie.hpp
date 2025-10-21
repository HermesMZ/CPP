/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:17:29 by mzimeris          #+#    #+#             */
/*   Updated: 2025/10/21 14:46:49 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

	std::string getName() const;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);
Zombie* zombieHorde( int N, std::string name );

#endif // ZOMBIE_HPP