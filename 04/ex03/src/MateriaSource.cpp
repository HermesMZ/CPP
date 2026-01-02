/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:42:24 by zoum              #+#    #+#             */
/*   Updated: 2025/12/15 13:00:29 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        _models[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) : IMateriaSource(other)
{
    for (int i = 0; i < 4; ++i)
    {
        if (other._models[i])
            _models[i] = other._models[i]->clone();
        else
            _models[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (_models[i])
            {
                delete _models[i];
                _models[i] = NULL;
            }
            if (other._models[i])
                _models[i] = other._models[i]->clone();
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i)
    {
        if (_models[i])
            delete _models[i];
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; ++i)
    {
        if (_models[i] == NULL)
        {
            _models[i] = m->clone();
            delete m;
            return;
        }
    }
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; ++i)
    {
        if (_models[i] && _models[i]->getType() == type)
            return _models[i]->clone();
    }
    return NULL;
}

void MateriaSource::printMaterias() const
{
    std::cout << "Materias disponibles dans la source:" << std::endl;
    int count = 0;
    for (int i = 0; i < 4; ++i)
    {
        if (_models[i])
        {
            std::cout << "  [" << i << "] " << _models[i]->getType() << std::endl;
            count++;
        }
    }
    if (count == 0)
        std::cout << "  (aucune materia apprise)" << std::endl;
}
