/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:36:24 by mzimeris          #+#    #+#             */
/*   Updated: 2026/01/13 17:52:55 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc == 1) {
		std::cout << "Test1 : 0" << std::endl;
		ScalarConverter::convert("0");
		std::cout << std::endl;
		std::cout << "Test2 : 42.0f" << std::endl;
		ScalarConverter::convert("42.0f");
		std::cout << std::endl;
		std::cout << "Test3 : 42.0" << std::endl;
		ScalarConverter::convert("42.0");
		std::cout << std::endl;
		std::cout << "Test4 : 42" << std::endl;
		ScalarConverter::convert("42");
		std::cout << std::endl;
		std::cout << "Test5 : intmax overflow" << std::endl;
		ScalarConverter::convert("2147483648");
		std::cout << std::endl;
		std::cout << "Test6 : c" << std::endl;
		ScalarConverter::convert("c");
		std::cout << std::endl;
		std::cout << "Test7 : nan" << std::endl;
		ScalarConverter::convert("nan");
		std::cout << std::endl;
		std::cout << "Test8 : +inff" << std::endl;
		ScalarConverter::convert("+inff");
		std::cout << std::endl;
		std::cout << "Test9 : -inff" << std::endl;
		ScalarConverter::convert("-inff");
		std::cout << std::endl;
		std::cout << "Test10 : +inf" << std::endl;
		ScalarConverter::convert("+inf");
		std::cout << std::endl;
		std::cout << "Test11 : -inf" << std::endl;
		ScalarConverter::convert("-inf");
		std::cout << std::endl;
		std::cout << "Test12 : 0cdz351~" << std::endl;
		ScalarConverter::convert("0cdz351~");
		std::cout << std::endl;
	} else {
		std::cout << "Converting : '" << argv[1] << "'" << std::endl;
		ScalarConverter::convert(argv[1]);
	}
	return 0;
}