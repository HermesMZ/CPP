/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:17:08 by mzimeris          #+#    #+#             */
/*   Updated: 2025/12/10 12:57:05 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main()
{
	std::cout << "=== TEST 1: Creation de MateriaSource et apprentissage ===" << std::endl;
	MateriaSource* src = new MateriaSource();
	
	std::cout << "\nAffichage de la source vide:" << std::endl;
	src->printMaterias();
	
	std::cout << "\nApprentissage de Ice..." << std::endl;
	src->learnMateria(new Ice());
	src->printMaterias();
	
	std::cout << "\nApprentissage de Cure..." << std::endl;
	src->learnMateria(new Cure());
	src->printMaterias();
	
	std::cout << "\n=== TEST 2: Creation de Materias ===" << std::endl;
	AMateria* ice = src->createMateria("ice");
	std::cout << "Materia creee: " << (ice ? ice->getType() : "null") << std::endl;
	
	AMateria* cure = src->createMateria("cure");
	std::cout << "Materia creee: " << (cure ? cure->getType() : "null") << std::endl;
	
	AMateria* unknown = src->createMateria("fire");
	std::cout << "Materia inconnue 'fire': " << (unknown ? "cree" : "null") << std::endl;
	
	std::cout << "\n=== TEST 3: Creation de personnages ===" << std::endl;
	ICharacter* me = new Character("Alice");
	std::cout << "Character " << me->getName() << " cree." << std::endl;
	ICharacter* bob = new Character("Bob");
	std::cout << "Character " << bob->getName() << " cree." << std::endl;

	
	std::cout << "\n=== TEST 4: Equipement de Materias ===" << std::endl;
	std::cout << "Alice equipe ice..." << std::endl;
	me->equip(ice);
	
	std::cout << "Alice equipe cure..." << std::endl;
	me->equip(cure);
	
	AMateria* ice2 = src->createMateria("ice");
	std::cout << "Alice equipe ice2..." << std::endl;
	me->equip(ice2);
	
	AMateria* cure2 = src->createMateria("cure");
	std::cout << "Alice equipe cure2..." << std::endl;
	me->equip(cure2);
	
	std::cout << "\nTentative d'equipement d'un 5eme materia (doit echouer)..." << std::endl;
	AMateria* ice3 = src->createMateria("ice");
	me->equip(ice3); // equip() va le delete automatiquement si l'inventaire est plein
	
	std::cout << "\n=== TEST 5: Utilisation des Materias ===" << std::endl;
	std::cout << "Alice utilise slot 0 sur Bob:" << std::endl;
	me->use(0, *bob);
	
	std::cout << "\nAlice utilise slot 1 sur Bob:" << std::endl;
	me->use(1, *bob);
	
	std::cout << "\nAlice utilise slot 2 sur Bob:" << std::endl;
	me->use(2, *bob);
	
	std::cout << "\nAlice utilise slot 3 sur Bob:" << std::endl;
	me->use(3, *bob);
	
	std::cout << "\nTentative d'utilisation d'un slot invalide (10):" << std::endl;
	me->use(10, *bob);
	
	std::cout << "\n=== TEST 6: Desequipement ===" << std::endl;
	std::cout << "Alice desequipe slot 1..." << std::endl;
	me->unequip(1);
	
	std::cout << "Alice utilise slot 1 (maintenant vide):" << std::endl;
	me->use(1, *bob);
	
	std::cout << "\n=== TEST 7: Re-equipement apres desequipement ===" << std::endl;
	AMateria* newCure = src->createMateria("cure");
	std::cout << "Alice equipe un nouveau cure dans le slot libre..." << std::endl;
	me->equip(newCure);
	
	std::cout << "Alice utilise le nouveau materia:" << std::endl;
	me->use(1, *bob);
	
	std::cout << "\n=== TEST 8: Test de copie profonde ===" << std::endl;
	Character* original = new Character("Original");
	AMateria* mat1 = src->createMateria("ice");
	AMateria* mat2 = src->createMateria("cure");
	original->equip(mat1);
	original->equip(mat2);
	
	std::cout << "\nCreation d'une copie..." << std::endl;
	Character* copy = new Character(*original);
	
	std::cout << "\nOriginal utilise ses materias sur Bob:" << std::endl;
	original->use(0, *bob);
	original->use(1, *bob);
	
	std::cout << "\nCopie utilise ses materias sur Bob:" << std::endl;
	copy->use(0, *bob);
	copy->use(1, *bob);
	
	std::cout << "\nSuppression de l'original..." << std::endl;
	delete original;
	
	std::cout << "La copie peut toujours utiliser ses materias:" << std::endl;
	copy->use(0, *bob);
	
	std::cout << "\n=== TEST 9: Apprentissage de plus de 4 materias ===" << std::endl;
	MateriaSource* bigSrc = new MateriaSource();
	std::cout << "Apprentissage de 5 materias (le 5eme doit echouer)..." << std::endl;
	bigSrc->learnMateria(new Ice());
	bigSrc->learnMateria(new Cure());
	bigSrc->learnMateria(new Ice());
	bigSrc->learnMateria(new Cure());
	std::cout << "Etat de bigSrc avant le 5eme:" << std::endl;
	bigSrc->printMaterias();
	bigSrc->learnMateria(new Ice()); // Ce dernier ne devrait pas etre appris
	std::cout << "Etat de bigSrc apres le 5eme (doit rester inchange):" << std::endl;
	bigSrc->printMaterias();
	
	std::cout << "\n=== TEST 10: Nettoyage ===" << std::endl;
	std::cout << "Suppression de copy..." << std::endl;
	delete copy;
	
	std::cout << "Suppression de Bob..." << std::endl;
	delete bob;
	
	std::cout << "Suppression d'Alice..." << std::endl;
	delete me;
	
	std::cout << "Suppression de src..." << std::endl;
	delete src;
	
	std::cout << "Suppression de bigSrc..." << std::endl;
	delete bigSrc;
	
	std::cout << "\n=== TOUS LES TESTS TERMINES ===" << std::endl;
	
	return 0;
}
