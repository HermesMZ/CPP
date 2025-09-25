/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:48:22 by mzimeris          #+#    #+#             */
/*   Updated: 2025/09/25 17:16:35 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
	PhoneBook phoneBook;
	Contact contact;
	
	// le programme tourne tant qu'on ne tape pas exit
	
	while (true)
	{
		std::string command;
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		
		if (command == "ADD")
		{
			// Ajouter un contact
			phoneBook.addContact();
		}
		else if (command == "SEARCH")
		{
			// Afficher les contacts
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