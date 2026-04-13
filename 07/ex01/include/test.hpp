/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 16:15:41 by mzimeris          #+#    #+#             */
/*   Updated: 2026/04/13 16:18:44 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>

template <typename T>
void printElement(const T& element) {
	std::cout << element << " ";
}

template <typename T>
void incrementElement(T& element) {
	element++;
}

template <typename T>
void doubleElement(T& element) {
	element *= 2;
}



#endif