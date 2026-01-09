/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 15:55:04 by mzimeris          #+#    #+#             */
/*   Updated: 2026/01/09 20:49:39 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default"), isSigned(false), gradeSign(150), gradeExecute(150) {}

AForm::~AForm() {}

AForm::AForm(const AForm& other)
	: name(other.name), isSigned(other.isSigned),
	  gradeSign(other.gradeSign), gradeExecute(other.gradeExecute) {}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		this->isSigned = other.isSigned;
		// 'name', 'gradeSign', and 'gradeExecute' are const and cannot be assigned to
	}
	return *this;
};

AForm::AForm(std::string const& name, int const gradeSign, int const gradeExecute)
	: name(name), isSigned(false), gradeSign(gradeSign), gradeExecute(gradeExecute) {
	if (gradeSign < 1 || gradeExecute < 1)
		throw GradeTooHighException();
	if (gradeSign > 150 || gradeExecute > 150)
		throw GradeTooLowException();
}

std::string const AForm::getName() const {
	return this->name;
}

bool AForm::getIsSigned() const {
	return this->isSigned;
}

int AForm::getGradeSign() const {
	return this->gradeSign;
}

int AForm::getGradeExecute() const {
	return this->gradeExecute;
}

void AForm::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() > this->gradeSign)
		throw GradeTooLowException();
	this->isSigned = true;
}

void AForm::execute(Bureaucrat const& executor) const {
	if (!this->isSigned)
		throw NotSignedException();
	if (executor.getGrade() > this->gradeExecute)
		throw GradeTooLowException();
	this->executeAction();
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade too low! (Form)";
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade too high! (Form)";
}

const char* AForm::NotSignedException::what() const throw() {
	return "Form is not signed!";
}

std::ostream& operator<<(std::ostream& output, const AForm& form) {
	output << "Form Name: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
	   << ", Grade Required to Sign: " << form.getGradeSign()
	   << ", Grade Required to Execute: " << form.getGradeExecute();
	return output;
}