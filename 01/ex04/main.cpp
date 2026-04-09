/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:20:44 by mzimeris          #+#    #+#             */
/*   Updated: 2025/11/27 12:34:14 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv)
{
	// nombre d'arguments
	if (argc != 4)
	{
		std::cerr << "Usage: " << "<File> <arg1> <arg2>" << std::endl;
		return 1;
	}

	std::ifstream src(argv[1]);
	// ouverture du fichier source
	if (!src.is_open())
	{
		std::cerr << "Error opening input file." << std::endl;
		return 1;
	}

	std::string filename = std::string(argv[1]) + ".replace";
	std::ofstream dst(filename.c_str());
	// ouverture du fichier destination
	if (!dst.is_open())
	{
		std::cerr << "Error creating output file." << std::endl;
		return 1;
	}

	std::string s1 = argv[2];
	std::string s2 = argv[3];
	
	// vérification que s1 n'est pas vide
	if (s1.empty())
	{
		std::cerr << "Error: s1 cannot be empty." << std::endl;
		src.close();
		dst.close();
		return 1;
	}

	std::string line;
	// lecture ligne par ligne
	while (std::getline(src, line))
	{
		size_t pos = 0;
		// remplacement de toutes les occurrences de s1 par s2 dans la ligne
		while (pos < line.length())
		{
			size_t found = line.find(s1, pos);
			// si aucune occurrence n'est trouvée, on sort de la boucle
			if (found == std::string::npos)
				break;
			// effacement de l'occurrence trouvée
			line.erase(found, s1.length());
			// insertion de la nouvelle chaîne à la place
			line.insert(found, s2);
			// mise à jour de la position
			pos = found + s2.length();
		}
		// écriture de la ligne modifiée dans le fichier de destination
		dst << line << std::endl;
	}
	
	// fermeture des fichiers
	src.close();
	dst.close();
	return 0;
}