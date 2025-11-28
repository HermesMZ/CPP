/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:43:08 by mzimeris          #+#    #+#             */
/*   Updated: 2025/11/28 12:28:45 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::ICharacter()
{
}

ICharacter::~ICharacter()
{
}

ICharacter::ICharacter(const ICharacter& other)
{
	(void)other;
}

ICharacter& ICharacter::operator=(const ICharacter& other)
{
	(void)other;
	return *this;
}
