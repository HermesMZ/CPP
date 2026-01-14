/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:42:34 by zoum              #+#    #+#             */
/*   Updated: 2026/01/14 16:42:35 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <iostream>
#include <cstdlib>

RPN::RPN() {}

RPN::~RPN() {}

const char* RPN::InvalidExpressionException::what() const throw() {
    return "Error";
}

const char* RPN::DivisionByZeroException::what() const throw() {
    return "Error: division by zero";
}

bool RPN::isOperator(const std::string& token) const {
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isNumber(const std::string& token) const {
    if (token.empty())
        return false;
    
    size_t start = 0;
    if (token[0] == '-' || token[0] == '+')
        start = 1;
    
    if (start >= token.length())
        return false;
    
    for (size_t i = start; i < token.length(); i++) {
        if (!std::isdigit(token[i]))
            return false;
    }
    
    return true;
}

int RPN::performOperation(int a, int b, char op) const {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0)
                throw DivisionByZeroException();
            return a / b;
        default:
            throw InvalidExpressionException();
    }
}

int RPN::evaluate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isNumber(token)) {
            int num = atoi(token.c_str());
            if (num >= 10 || num < 0)
                throw InvalidExpressionException();
            _stack.push(num);
        } else if (isOperator(token)) {
            if (_stack.size() < 2)
                throw InvalidExpressionException();
            
            int b = _stack.top();
            _stack.pop();
            int a = _stack.top();
            _stack.pop();
            
            int result = performOperation(a, b, token[0]);
            _stack.push(result);
        } else {
            throw InvalidExpressionException();
        }
    }

    if (_stack.size() != 1)
        throw InvalidExpressionException();

    return _stack.top();
}
