/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 20:18:04 by mzimeris          #+#    #+#             */
/*   Updated: 2026/01/09 20:49:39 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm",
	25, 5), target("default") {}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm&other) :
	AForm("PresidentialPardonForm", 25, 5), target(other.target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		this->target = other.target;
	}
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target) :
	AForm("PresidentialPardonForm", 25, 5), target(target) {}

void PresidentialPardonForm::executeAction() const {
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}