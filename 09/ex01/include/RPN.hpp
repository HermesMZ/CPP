/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:42:01 by zoum              #+#    #+#             */
/*   Updated: 2026/01/14 16:42:02 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <exception>

class RPN {
private:
    std::stack<int> _stack;

    RPN(const RPN& other);
    RPN& operator=(const RPN& other);

    bool isOperator(const std::string& token) const;
    bool isNumber(const std::string& token) const;
    int performOperation(int a, int b, char op) const;

public:
    RPN();
    ~RPN();

    int evaluate(const std::string& expression);

    class InvalidExpressionException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class DivisionByZeroException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

#endif
