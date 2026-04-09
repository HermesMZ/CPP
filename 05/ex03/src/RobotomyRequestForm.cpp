/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 20:13:07 by mzimeris          #+#    #+#             */
/*   Updated: 2026/01/09 20:49:39 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm",
	72, 45), target("default") {}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm&other) :
	AForm("RobotomyRequestForm", 72, 45), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		this->target = other.target;
	}
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target) :
	AForm("RobotomyRequestForm", 72, 45), target(target) {}

void RobotomyRequestForm::executeAction() const {
	std::cout << "Bzzzzzz... Vrrrrrrr... *drilling noises*" << std::endl;
	if (time(NULL) % 2)
		std::cout << this->target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "The robotomy on " << this->target << " has failed." << std::endl;
}