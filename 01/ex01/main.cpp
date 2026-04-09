/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:24:40 by mzimeris          #+#    #+#             */
/*   Updated: 2025/10/17 11:56:57 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie* z = newZombie("Zouuuumbie");
	Zombie* horde = zombieHorde(5, "Hordie");
    delete z;
	for (int i = 0; i < 5; ++i)
		horde[i].announce();
    delete[] horde;
    return 0;
}