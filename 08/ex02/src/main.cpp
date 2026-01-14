/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:10:20 by zoum              #+#    #+#             */
/*   Updated: 2026/01/14 17:10:21 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	std::cout << "=== Test with MutantStack ===" << std::endl;
	{
		MutantStack<int> mstack;
		
		mstack.push(5);
		mstack.push(17);
		
		std::cout << "Top: " << mstack.top() << std::endl;
		
		mstack.pop();
		
		std::cout << "Size: " << mstack.size() << std::endl;
		
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		
		++it;
		--it;
		
		std::cout << "Elements:" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		
		std::stack<int> s(mstack);
	}

	std::cout << "\n=== Same test with std::list ===" << std::endl;
	{
		std::list<int> mlist;
		
		mlist.push_back(5);
		mlist.push_back(17);
		
		std::cout << "Back: " << mlist.back() << std::endl;
		
		mlist.pop_back();
		
		std::cout << "Size: " << mlist.size() << std::endl;
		
		mlist.push_back(3);
		mlist.push_back(5);
		mlist.push_back(737);
		mlist.push_back(0);
		
		std::list<int>::iterator it = mlist.begin();
		std::list<int>::iterator ite = mlist.end();
		
		++it;
		--it;
		
		std::cout << "Elements:" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	std::cout << "\n=== Test reverse iterators ===" << std::endl;
	{
		MutantStack<int> mstack;
		
		for (int i = 1; i <= 5; i++)
			mstack.push(i * 10);

		std::cout << "Forward iteration:" << std::endl;
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "Reverse iteration:" << std::endl;
		for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

	std::cout << "\n=== Test copy constructor ===" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);

		MutantStack<int> copy(mstack);

		std::cout << "Original stack:" << std::endl;
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "Copied stack:" << std::endl;
		for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

	std::cout << "\n=== Test assignment operator ===" << std::endl;
	{
		MutantStack<int> mstack1;
		mstack1.push(10);
		mstack1.push(20);

		MutantStack<int> mstack2;
		mstack2.push(99);

		mstack2 = mstack1;

		std::cout << "Stack after assignment:" << std::endl;
		for (MutantStack<int>::iterator it = mstack2.begin(); it != mstack2.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

	std::cout << "\n=== Test with strings ===" << std::endl;
	{
		MutantStack<std::string> mstack;
		
		mstack.push("Hello");
		mstack.push("World");
		mstack.push("!");

		std::cout << "String stack:" << std::endl;
		for (MutantStack<std::string>::iterator it = mstack.begin(); it != mstack.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

	return 0;
}
