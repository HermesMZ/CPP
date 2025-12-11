/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:51:15 by mzimeris          #+#    #+#             */
/*   Updated: 2025/12/10 11:04:35 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;
	delete i;
	delete j;
	delete meta;
	std::cout << std::endl;

	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	dog->makeSound();
	cat->makeSound();
	std::cout << std::endl;
	delete cat;
	delete dog;
	std::cout << std::endl;

	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	const WrongCat* wrongKitty = new WrongCat();
	wrongAnimal->makeSound();
	wrongCat->makeSound();
	wrongKitty->makeSound();
	delete wrongAnimal;
	delete wrongCat;
	delete wrongKitty;

return 0;
}