/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:36:27 by mzimeris          #+#    #+#             */
/*   Updated: 2025/10/11 04:27:19 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();

		// Enable/disable informational messages (constructor/destructor/add/remove)
		static void setVerbose(bool v);
		static bool isVerbose();

		void addContact();
		void addContact(const Contact& contact);
		void displayContacts() const;		
	private:
		int contactCount;
		Contact contacts[8];
};

#endif // PHONEBOOK_HPP