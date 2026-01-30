/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:28:07 by mzimeris          #+#    #+#             */
/*   Updated: 2026/01/09 21:05:56 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm",
	145, 137), target("default") {}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm&other) :
	AForm("ShrubberyCreationForm", 145, 137), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		this->target = other.target;
	}
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target) :
	AForm("ShrubberyCreationForm", 145, 137), target(target) {}

void ShrubberyCreationForm::executeAction() const {
	std::string filename = this->target + "_shrubbery";
	std::ofstream outfile(filename.c_str());
	if (!outfile) {
		std::cerr << "Error creating file: " << filename << std::endl;
		return;
	}

	outfile << "       *\n"
			   "      ***\n"
			   "     *****\n"
			   "    *******\n"
			   "   *********\n"
			   "  ***********\n"
			   " *************\n"
			   "***************\n"
			   "      |||\n"
			   "      |||" << std::endl;
	outfile.close();
}