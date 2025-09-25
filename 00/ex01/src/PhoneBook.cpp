/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:36:12 by mzimeris          #+#    #+#             */
/*   Updated: 2025/09/25 17:25:47 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	std::cout << "PhoneBook created!" << std::endl;
	this->contactCount = 0;
}

PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook destroyed!" << std::endl;
}

void PhoneBook::addContact()
{
	if (this->contactCount < 8)
	{
		Contact newContact;
		std::string firstName;
		std::string phoneNumber;

		std::cout << "Enter first name: ";
		std::getline(std::cin, firstName);

		std::cout << "Enter phone number: ";
		std::getline(std::cin, phoneNumber);

		newContact.setFirstName(firstName);
		newContact.setPhoneNumber(phoneNumber);

		this->contacts[this->contactCount] = newContact; // Ajouter le contact au tableau
		this->contactCount++;
		std::cout << "Contact added! Total contacts: " << this->contactCount << std::endl;
	}
	else
	{
		std::cout << "PhoneBook is full! Cannot add more contacts." << std::endl;
	}
}

void PhoneBook::displayContacts() const
{
	if (this->contactCount == 0)
	{
		std::cout << "No contacts to display." << std::endl;
		return;
	}
	std::cout << "searching by first name" << std::endl;
	std::string searchName;
	std::getline(std::cin, searchName);

	bool found = false;
	for (int i = 0; i < this->contactCount; i++)
	{
		if (this->contacts[i].getFirstName() == searchName)
		{
			std::cout << "Found contact: " << this->contacts[i].getFirstName() << " - " << this->contacts[i].getPhoneNumber() << std::endl;
			found = true;
			break;
		}
	}
	if (!found)
	{
		std::cout << "No contact found with the name: " << searchName << std::endl;
	}
}