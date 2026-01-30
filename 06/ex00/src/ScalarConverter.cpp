/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 14:39:05 by zoum              #+#    #+#             */
/*   Updated: 2026/01/11 15:34:35 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

static void printChar(double value)
{
	if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

static void printInt(double value)
{
	if (std::isnan(value) || std::isinf(value) || 
		value > std::numeric_limits<int>::max() || 
		value < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

static void printFloat(double value)
{
	if (!std::isnan(value) && !std::isinf(value) && 
		(value > std::numeric_limits<float>::max() || 
		 value < -std::numeric_limits<float>::max()))
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) 
			<< static_cast<float>(value) << "f" << std::endl;
}

static void printDouble(double value)
{
	std::cout << "double: " << std::fixed << std::setprecision(1) 
		<< value << std::endl;
}

static void printAll(double value)
{
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}

bool ScalarConverter::isChar(const std::string &literal)
{
	return (literal.length() == 1 && !std::isdigit(literal[0]) && std::isprint(literal[0]));
}

bool ScalarConverter::isInt(const std::string &literal)
{
	if (literal.empty())
		return false;
	
	size_t i = 0;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	
	if (i >= literal.length())
		return false;
	
	while (i < literal.length())
	{
		if (!std::isdigit(literal[i]))
			return false;
		i++;
	}
	return true;
}

bool ScalarConverter::isFloat(const std::string &literal)
{
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		return true;
	
	if (literal.empty() || literal[literal.length() - 1] != 'f')
		return false;
	
	std::string num = literal.substr(0, literal.length() - 1);
	char *end;
	strtod(num.c_str(), &end);
	return (*end == '\0' && !num.empty());
}

bool ScalarConverter::isDouble(const std::string &literal)
{
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		return true;
	
	if (literal.empty())
		return false;
	
	char *end;
	strtod(literal.c_str(), &end);
	return (*end == '\0');
}

static double parseValue(const std::string &literal)
{
	if (literal == "nan" || literal == "nanf")
		return std::numeric_limits<double>::quiet_NaN();
	if (literal == "+inf" || literal == "+inff")
		return std::numeric_limits<double>::infinity();
	if (literal == "-inf" || literal == "-inff")
		return -std::numeric_limits<double>::infinity();
	return std::atof(literal.c_str());
}

void ScalarConverter::convert(const std::string &literal)
{
	double value;

	if (isChar(literal))
		value = static_cast<double>(literal[0]);
	else if (isInt(literal))
		value = std::atof(literal.c_str());
	else if (isFloat(literal))
		value = parseValue(literal);
	else if (isDouble(literal))
		value = parseValue(literal);
	else
	{
		std::cout << "Error: Invalid literal" << std::endl;
		return;
	}

	printAll(value);
}
