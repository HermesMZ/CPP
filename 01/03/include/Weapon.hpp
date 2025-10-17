/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:42:17 by mzimeris          #+#    #+#             */
/*   Updated: 2025/10/17 15:57:38 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
private:
	std::string type;
public:
	Weapon(std::string type);
	~Weapon();

	std::string getType() const;
	void setType(std::string type);
};

#endif /* WEAPON_HPP */