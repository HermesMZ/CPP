/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:36:12 by mzimeris          #+#    #+#             */
/*   Updated: 2025/10/21 14:53:19 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <limits>
#include <sstream>

static bool g_phoneBookVerbose = true;

void PhoneBook::setVerbose(bool v)
{
	g_phoneBookVerbose = v;
}

bool PhoneBook::isVerbose()
{
	return g_phoneBookVerbose;
}

PhoneBook::PhoneBook()
{
	if (g_phoneBookVerbose)
		std::cout << "PhoneBook created!" << std::endl;
	this->contactCount = 0;
}

PhoneBook::~PhoneBook()
{
	if (g_phoneBookVerbose)
		std::cout << "PhoneBook destroyed!" << std::endl;
}

static bool readNonEmptyField(const std::string &prompt, std::string &out)
{
	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, out))
		{
			std::cout << std::endl;
			return false;
		}
		if (out.find_first_not_of(" \t\r\n") != std::string::npos)
			return true;
		std::cout << "Field cannot be empty or only spaces. Please try again." << std::endl;
	}
}

void PhoneBook::addContact()
{
	if (this->contactCount == 8)
	{
		for (int i = 1; i < this->contactCount; i++)
		{
			this->contacts[i - 1] = this->contacts[i];
		}
		this->contactCount--;
		if (g_phoneBookVerbose) std::cout << "PhoneBook is full! Oldest contact removed." << std::endl;
	}

	Contact newContact;
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	if (!readNonEmptyField("Enter first name: ", firstName))
		return;
	if (!readNonEmptyField("Enter last name: ", lastName))
		return;
	if (!readNonEmptyField("Enter nickname: ", nickname))
		return;
	if (!readNonEmptyField("Enter phone number: ", phoneNumber))
		return;
	if (!readNonEmptyField("Enter darkest secret: ", darkestSecret))
		return;

	newContact.setFirstName(firstName);
	newContact.setLastName(lastName);
	newContact.setNickname(nickname);
	newContact.setPhoneNumber(phoneNumber);
	newContact.setDarkestSecret(darkestSecret);

	this->contacts[this->contactCount] = newContact;
	this->contactCount++;
	if (g_phoneBookVerbose) std::cout << "Contact added! Total contacts: " << this->contactCount << std::endl;
}

void PhoneBook::addContact(const Contact& contact)
{
	if (this->contactCount == 8)
	{
		for (int i = 1; i < this->contactCount; i++)
		{
			this->contacts[i - 1] = this->contacts[i];
		}
		this->contactCount--;
		if (g_phoneBookVerbose) std::cout << "PhoneBook is full! Oldest contact removed." << std::endl;
	}

	this->contacts[this->contactCount] = contact;
	this->contactCount++;
	if (g_phoneBookVerbose) std::cout << "Contact added! Total contacts: " << this->contactCount << std::endl;
}

// SEARCH : affiche le contact demandé
// ◦ Affiche les contacts enregistrés sous la forme d’une liste de 4 colonnes : index,
// first name, last name et nickname.
// ◦ Chaque colonne doit faire 10 caractères de long. Elles doivent être séparées
// par un pipe (’|’). Leur texte est aligné à droite. Si le texte dépasse la largeur
// de la colonne, il faut le tronquer et remplacer le dernier caractère affiché par
// un point (’.’).
// ◦ Ensuite, le programme demande à l’utilisateur d’entrer l’index du contact à af-
// ficher. Si l’index ou son format sont incorrects, gérez cela de manière pertinente.
// Sinon, affichez les informations du contact, une par ligne

// Utility: format a field to 10 chars, truncating and adding a '.' if too long
static std::string formatField(const std::string &s)
{
	if (s.size() > 10)
		return s.substr(0, 9) + ".";
	return s;
}

void PhoneBook::displayContacts() const
{
	if (this->contactCount == 0)
	{
		std::cout << "No contacts to display." << std::endl;
		return;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	for (int i = 0; i < this->contactCount; i++)
	{
		std::cout << "|         " << i << "|";
		std::cout << std::setw(10) << std::right << formatField(this->contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << std::right << formatField(this->contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << std::right << formatField(this->contacts[i].getNickname()) << "|" << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
	}

// ◦ Ensuite, le programme demande à l’utilisateur d’entrer l’index du contact à af-
// ficher. Si l’index ou son format sont incorrects, gérez cela de manière pertinente.
// Sinon, affichez les informations du contact, une par ligne

	std::string line;
	std::cout << "Enter the index of the contact to display: ";
	if (!std::getline(std::cin, line))
	{
		std::cout << std::endl;
		return;
	}
	if (line.empty())
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}

	std::stringstream ss(line);
	int index;
	if (!(ss >> index) || (ss >> std::ws, !ss.eof()) || index < 0 || index >= this->contactCount)
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}

	const Contact &c = this->contacts[index];
	std::cout << "First name: " << c.getFirstName() << std::endl;
	std::cout << "Last name: " << c.getLastName() << std::endl;
	std::cout << "Nickname: " << c.getNickname() << std::endl;
	std::cout << "Phone number: " << c.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << c.getDarkestSecret() << std::endl;
}