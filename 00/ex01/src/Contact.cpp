/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:41:13 by mzimeris          #+#    #+#             */
/*   Updated: 2025/09/25 17:20:26 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	std::cout << "Contact created!" << std::endl;
}

Contact::~Contact()
{
	std::cout << "Contact destroyed!" << std::endl;
}

void Contact::setFirstName(const std::string& name)
{
	this->firstName = name;
}

void Contact::setLastName(const std::string& name)
{
	this->lastName = name;
}

void Contact::setPhoneNumber(const std::string& phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

std::string Contact::getFirstName() const
{
	return this->firstName;
}

std::string Contact::getLastName() const
{
	return this->lastName;
}

std::string Contact::getPhoneNumber() const
{
	return this->phoneNumber;
}