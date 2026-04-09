/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 21:12:31 by mzimeris          #+#    #+#             */
/*   Updated: 2026/01/09 21:25:53 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <string>

class Intern {
	public:
		Intern();
		~Intern();
		Intern(const Intern&);
		Intern& operator=(const Intern&);

		AForm* makeForm(const std::string& formName, const std::string& target);
	
	private:
			AForm* createShrubberyCreationForm(const std::string& target);
			AForm* createRobotomyRequestForm(const std::string& target);
			AForm* createPresidentialPardonForm(const std::string& target);
};