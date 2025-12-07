/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:42:24 by zoum              #+#    #+#             */
/*   Updated: 2025/12/04 13:42:25 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

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
    // inventory full -> delete the passed materia to avoid leak
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
