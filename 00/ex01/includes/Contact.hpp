/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:40:02 by mzimeris          #+#    #+#             */
/*   Updated: 2025/09/25 17:25:12 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
	public:
		Contact();
		~Contact();
		
		void setFirstName(const std::string& name);
		void setPhoneNumber(const std::string& phoneNumber);

		std::string getFirstName() const;
		std::string getPhoneNumber() const;
	private:
		std::string firstName;
		std::string phoneNumber;


};

#endif // CONTACT_HPP