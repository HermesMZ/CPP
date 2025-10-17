/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:20:44 by mzimeris          #+#    #+#             */
/*   Updated: 2025/10/17 16:56:46 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Create a program that takes three parameters in the following order: a filename and
two strings, s1 and s2.
It must open the file <filename> and copy its content into a new file
<filename>.replace, replacing every occurrence of s1 with s2.
Using C file manipulation functions is forbidden and will be considered cheating. All
the member functions of the class std::string are allowed, except replace. Use them
wisely!
Of course, handle unexpected inputs and errors. You must create and turn in your
own tests to ensure that your program works as expected.
*/

#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << "<File> <arg1> <arg2>" << std::endl;
		return 1;
	}

	std::ifstream src(argv[1]);
	if (!src.is_open())
	{
		std::cerr << "Error opening input file." << std::endl;
		return 1;
	}

	std::string filename = std::string(argv[1]) + ".replace";
	std::ofstream dst(filename.c_str());
	if (!dst.is_open())
	{
		std::cerr << "Error creating output file." << std::endl;
		return 1;
	}

	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string line;
	while (std::getline(src, line))
	{
		for (size_t pos = 0; pos <= line.length(); pos++)
		{
			if (line.compare(pos, s1.length(), s1) == 0)
			{
				line.erase(pos, s1.length());
				line.insert(pos, s2);
				pos += s2.length() - 1;
			}
		}
		dst << line << std::endl;
	}
	return 0;
}