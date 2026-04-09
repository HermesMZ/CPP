/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:26:23 by mzimeris          #+#    #+#             */
/*   Updated: 2026/04/09 15:25:45 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
}

Cure::Cure(const Cure& other) : AMateria(other) {
}

Cure& Cure::operator=(const Cure& other) {
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return *this;
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure::~Cure() {
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}