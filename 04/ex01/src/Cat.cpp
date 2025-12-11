/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:20:40 by mzimeris          #+#    #+#             */
/*   Updated: 2025/12/10 11:13:07 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& other) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = other.type;
	this->brain = new Brain(*other.brain);
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		this->type = other.type;
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow! Meow!" << std::endl;
}