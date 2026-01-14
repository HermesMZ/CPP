/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:36:24 by mzimeris          #+#    #+#             */
/*   Updated: 2026/01/13 23:21:22 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
	// Création d'un objet Data
Data originalData;
originalData.id = 42;
originalData.name = "Test Object";
originalData.value = 3.14159;

std::cout << "=== Test de Serialization ==="<< std::endl << std::endl;

std::cout << "Original Data:" << std::endl;
std::cout << "  Address: " << &originalData << std::endl;
std::cout << "  id: " << originalData.id << std::endl;
std::cout << "  name: " << originalData.name << std::endl;
std::cout << "  value: " << originalData.value << std::endl;
std::cout << std::endl;

// Sérialisation
uintptr_t serialized = Serializer::serialize(&originalData);
std::cout << "Serialized (uintptr_t): " << serialized << std::endl;
std::cout << std::endl;

// Désérialisation
Data* deserialized = Serializer::deserialize(serialized);
std::cout << "Deserialized Data:" << std::endl;
std::cout << "  Address: " << deserialized << std::endl;
std::cout << "  id: " << deserialized->id << std::endl;
std::cout << "  name: " << deserialized->name << std::endl;
std::cout << "  value: " << deserialized->value << std::endl;
std::cout << std::endl;

// Vérification
if (deserialized == &originalData) {
std::cout << "✓ SUCCESS: Les pointeurs sont identiques!" << std::endl;
} else {
std::cout << "✗ FAILURE: Les pointeurs sont différents!" << std::endl;
}

std::cout << "\n=== Test DANGEREUX: Mélange de types ==="<< std::endl << std::endl;

int wrongType = 12345;
std::cout << "Original int:" << std::endl;
std::cout << "  Address: " << &wrongType << std::endl;
std::cout << "  Value: " << wrongType << std::endl;
std::cout << std::endl;

// Sérialisation d'un int* (mauvais type!)
uintptr_t wrongSerialized = reinterpret_cast<uintptr_t>(&wrongType);
std::cout << "Serialized int* (uintptr_t): " << wrongSerialized << std::endl;
std::cout << std::endl;

// Désérialisation comme Data* (ERREUR!)
Data* wrongDeserialized = Serializer::deserialize(wrongSerialized);
std::cout << "Désérialisé comme Data* (comportement indéfini):" << std::endl;
std::cout << "  Address: " << wrongDeserialized << std::endl;

std::cout << "  Tentative d'accès aux membres:" << std::endl;
std::cout << "  id: " << wrongDeserialized->id << std::endl;
std::cout << "  value: " << wrongDeserialized->value << std::endl;
// std::cout << "  name: " << wrongDeserialized->name << std::endl;

return 0;
}
