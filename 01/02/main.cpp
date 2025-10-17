/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:35:06 by mzimeris          #+#    #+#             */
/*   Updated: 2025/10/17 12:44:16 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "The memory address of the string variable" << std::endl;
	std::cout << &str << std::endl;

	std::cout << "\nThe memory address held by stringPTR." << std::endl;
	std::cout << stringPTR << std::endl;

	std::cout << "\nThe memory address held by stringREF." << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << "\nThe value of the string variable." << std::endl;
	std::cout << str << std::endl;
	
	std::cout << "\nThe value pointed to by stringPTR." << std::endl;
	std::cout << *stringPTR << std::endl;
	
	std::cout << "\nThe value pointed to by stringREF." << std::endl;
	std::cout << stringREF << std::endl;

	return 0;
}