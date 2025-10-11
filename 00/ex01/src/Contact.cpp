/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:41:13 by mzimeris          #+#    #+#             */
/*   Updated: 2025/10/11 04:27:19 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

static bool g_contactVerbose = true;

void Contact::setVerbose(bool v)
{
	g_contactVerbose = v;
}

bool Contact::isVerbose()
{
	return g_contactVerbose;
}

Contact::Contact()
{
	if (g_contactVerbose)
		std::cout << "Contact created!" << std::endl;
}

Contact::~Contact()
{
	if (g_contactVerbose)
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

void Contact::setNickname(const std::string& nickname)
{
	this->nickname = nickname;
}
	
void Contact::setPhoneNumber(const std::string& phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& darkestSecret)
{
	this->darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const
{
	return this->firstName;
}

std::string Contact::getLastName() const
{
	return this->lastName;
}

std::string Contact::getNickname() const
{
	return this->nickname;
}

std::string Contact::getPhoneNumber() const
{
	return this->phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
	return this->darkestSecret;
}