/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:20:55 by mzimeris          #+#    #+#             */
/*   Updated: 2025/09/25 16:18:59 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		std::cout << std::endl;
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			if (i > 1)
				std::cout << " ";
			std::string str = argv[i];
			for (size_t j = 0; j < str.length(); j++)
			{
				str[j] = toupper(str[j]);
			}
			std::cout << str;
		}
		std::cout << std::endl;
	}
}