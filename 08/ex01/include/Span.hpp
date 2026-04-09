/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:09:54 by zoum              #+#    #+#             */
/*   Updated: 2026/01/14 17:09:55 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <limits>

class Span
{
private:
	unsigned int _maxSize;
	std::vector<int> _numbers;

	Span();

public:
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int number);
	
	template <typename Iterator>
	void addNumber(Iterator begin, Iterator end)
	{
		while (begin != end)
		{
			if (_numbers.size() >= _maxSize)
				throw std::length_error("Span is already full");
			_numbers.push_back(*begin);
			++begin;
		}
	}

	int shortestSpan() const;
	int longestSpan() const;

	class SpanFullException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class NoSpanException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

#endif
