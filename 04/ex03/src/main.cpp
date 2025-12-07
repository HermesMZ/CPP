/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:17:08 by mzimeris          #+#    #+#             */
/*   Updated: 2025/12/04 13:44:40 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	AMateria* tmp;

	std::cout << "=== TEST: IMateriaSource::learnMateria + createMateria + Character::equip/use ===" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << std::endl << "=== TEST: Character::equip when full (equip 5th materia should do nothing) ===" << std::endl;
	// fill inventory
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp); // this is 5th, should not be equipped

	std::cout << std::endl << "=== TEST: Character::unequip (does not delete materia) ===" << std::endl;
	// unequip slot 1 and try to use it
	me->unequip(1);
	me->use(1, *bob); // nothing should happen

	std::cout << std::endl << "=== TEST: Character::use with invalid indices ===" << std::endl;
	me->use(-1, *bob);
	me->use(42, *bob);

	std::cout << std::endl << "=== TEST: Character copy constructor (deep copy of materias) ===" << std::endl;
	Character* copy = new Character(*(static_cast<Character*>(me)));
	delete me; // original deleted, copy should still work
	copy->use(0, *bob);
	copy->use(2, *bob);

	std::cout << std::endl << "=== TEST: Character assignment operator (deep copy) ===" << std::endl;
	Character assignSrc("assignSrc");
	tmp = src->createMateria("cure");
	assignSrc.equip(tmp);
	Character assignDst("assignDst");
	assignDst = assignSrc;
	assignDst.use(0, *bob);

	std::cout << std::endl << "=== TEST: IMateriaSource copy (learnMateria clones) ===" << std::endl;
	MateriaSource* msrc = new MateriaSource();
	msrc->learnMateria(new Ice());
	msrc->learnMateria(new Cure());
	MateriaSource copySrc(*msrc);
	AMateria* created = copySrc.createMateria("ice");
	if (created)
	{
		std::cout << "createMateria from copied MateriaSource produced: " << created->getType() << std::endl;
		delete created;
	}

	// cleanup
	delete msrc;
	delete copy;
	delete bob;
	delete src;

	return 0;
}