/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 15:55:04 by mzimeris          #+#    #+#             */
/*   Updated: 2026/01/02 16:22:53 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default"), isSigned(false), gradeSign(150), gradeExecute(150) {}

Form::~Form() {}

Form::Form(const Form& other)
	: name(other.name), isSigned(other.isSigned),
	  gradeSign(other.gradeSign), gradeExecute(other.gradeExecute) {}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		this->isSigned = other.isSigned;
		// 'name', 'gradeSign', and 'gradeExecute' are const and cannot be assigned to
	}
	return *this;
};

Form::Form(std::string const& name, int const gradeSign, int const gradeExecute)
	: name(name), isSigned(false), gradeSign(gradeSign), gradeExecute(gradeExecute) {
	if (gradeSign < 1 || gradeExecute < 1)
		throw GradeTooHighException();
	if (gradeSign > 150 || gradeExecute > 150)
		throw GradeTooLowException();
}

std::string const Form::getName() const {
	return this->name;
}

bool Form::getIsSigned() const {
	return this->isSigned;
}

int Form::getGradeSign() const {
	return this->gradeSign;
}

int Form::getGradeExecute() const {
	return this->gradeExecute;
}

void Form::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() > this->gradeSign)
		throw GradeTooLowException();
	this->isSigned = true;
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low! (Form)";
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade too high! (Form)";
}

std::ostream& operator<<(std::ostream& output, const Form& form) {
	output << "Form Name: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
	   << ", Grade Required to Sign: " << form.getGradeSign()
	   << ", Grade Required to Execute: " << form.getGradeExecute();
	return output;
}