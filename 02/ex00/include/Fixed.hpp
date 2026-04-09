/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:32:39 by mzimeris          #+#    #+#             */
/*   Updated: 2025/10/29 14:21:06 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int _integer;
		static const int _fractionalBits = 8;
	public:
		// Un constructeur par défaut qui initialisera la valeur du nombre à virgule fixe à 0.
		Fixed();
		// ◦Un constructeur de recopie.
		Fixed(const Fixed &other);
		// ◦Une surcharge de l’opérateur d’affectation.
		Fixed &operator=(const Fixed &other);
		// ◦Un destructeur.
		~Fixed();
		// ◦Une fonction membre int getRawBits( void ) const;
		// qui retourne la valeur du nombre à virgule fixe sans la convertir.
		int getRawBits( void ) const;
		// ◦Une fonction membre void setRawBits( int const raw );
		// qui initialise la valeur du nombre à virgule fixe avec celle passée en paramètre.
		void setRawBits( int const raw );
};
#endif /* FIXED_HPP */