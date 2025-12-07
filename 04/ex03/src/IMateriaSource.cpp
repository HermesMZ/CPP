/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:30:37 by mzimeris          #+#    #+#             */
/*   Updated: 2025/12/04 13:34:26 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

IMateriaSource::~IMateriaSource()
{
}

IMateriaSource::IMateriaSource()
{
}

IMateriaSource::IMateriaSource(const IMateriaSource& other)
{
	(void)other;
}

IMateriaSource& IMateriaSource::operator=(const IMateriaSource& other)
{
	(void)other;
	return *this;
}

