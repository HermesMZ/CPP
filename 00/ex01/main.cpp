/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:48:22 by mzimeris          #+#    #+#             */
/*   Updated: 2025/10/11 04:26:45 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

static void test(PhoneBook &phoneBook)
{
	Contact c;

	c.setFirstName("Alice");
	c.setLastName("Smith");
	c.setNickname("Ali");
	c.setPhoneNumber("1111111111");
	c.setDarkestSecret("Afraid of spiders");
	phoneBook.addContact(c);

	c.setFirstName("Bob");
	c.setLastName("Johnson");
	c.setNickname("Bobby");
	c.setPhoneNumber("2222222222");
	c.setDarkestSecret("Never learned to ride a bike");
	phoneBook.addContact(c);

	c.setFirstName("Charlie");
	c.setLastName("Brown");
	c.setNickname("Chuck");
	c.setPhoneNumber("3333333333");
	c.setDarkestSecret("Hates Mondays");
	phoneBook.addContact(c);

	c.setFirstName("Diana");
	c.setLastName("Prince");
	c.setNickname("Wonder");
	c.setPhoneNumber("4444444444");
	c.setDarkestSecret("Collects action figures");
	phoneBook.addContact(c);

	c.setFirstName("Eve");
	c.setLastName("Adams");
	c.setNickname("Evie");
	c.setPhoneNumber("5555555555");
	c.setDarkestSecret("Sings in the shower loudly");
	phoneBook.addContact(c);

	c.setFirstName("Frank");
	c.setLastName("Miller");
	c.setNickname("Franky");
	c.setPhoneNumber("6666666666");
	c.setDarkestSecret("Can\'t whistle");
	phoneBook.addContact(c);

	c.setFirstName("Grace");
	c.setLastName("Hopper");
	c.setNickname("G.");
	c.setPhoneNumber("7777777777");
	c.setDarkestSecret("Writes comments in binary");
	phoneBook.addContact(c);

	c.setFirstName("Hank");
	c.setLastName("Pym");
	c.setNickname("Pym");
	c.setPhoneNumber("8888888888");
	c.setDarkestSecret("Talks to plants");
	phoneBook.addContact(c);

	c.setFirstName("Ivy");
	c.setLastName("Green");
	c.setNickname("Ivy");
	c.setPhoneNumber("9999999999");
	c.setDarkestSecret("Afraid of heights");
	phoneBook.addContact(c);
}

int main()
{
	PhoneBook::setVerbose(false);
	Contact::setVerbose(false);
	
	PhoneBook phoneBook;
	test(phoneBook);

	while (true)
	{
		std::string command;
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		
		if (command == "ADD")
		{
			phoneBook.addContact();
		}
		else if (command == "SEARCH")
		{
			phoneBook.displayContacts();
		}
		else if (command == "EXIT")
		{
			std::cout << "Exiting the program." << std::endl;
			break;
		}
		else
		{
			std::cout << "Invalid command. Please try again." << std::endl;
		}
	}
	return 0;
}