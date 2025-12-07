/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:50:00 by mzimeris          #+#    #+#             */
/*   Updated: 2025/12/04 13:34:26 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// ground storage for unequipped materias (no STL allowed)
static const int GROUND_CAPACITY = 256;
static AMateria* ground_storage[GROUND_CAPACITY];
static int ground_count = 0;

static void ground_add(AMateria* m)
{
	if (!m)
		return;
	if (ground_count < GROUND_CAPACITY)
	{
		ground_storage[ground_count++] = m;
	}
	else
	{
		// no space: delete to avoid leak
		delete m;
	}
}

// Cleaner to delete materias left on the ground at program exit
static struct GroundCleaner {
	~GroundCleaner()
	{
		for (int i = 0; i < ground_count; ++i)
		{
			if (ground_storage[i])
				delete ground_storage[i];
			ground_storage[i] = NULL;
		}
		ground_count = 0;
	}
} groundCleanerInstance;

Character::Character() : _name("default")
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(std::string const & name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character& other) : ICharacter(other), _name(other._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
			{
				delete _inventory[i];
				_inventory[i] = NULL;
			}
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

std::string const & Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	if (!m)
		return;
	
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return;
		}
	}
	// inventory full -> delete the materia to avoid leaking ownership
	delete m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		return;
    
	if (_inventory[idx])
	{
		// Put the materia on the ground (caller or environment may pick it up).
		ground_add(_inventory[idx]);
		_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
		return;
	
	if (_inventory[idx])
		_inventory[idx]->use(target);
}
