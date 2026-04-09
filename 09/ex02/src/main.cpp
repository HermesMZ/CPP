/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:11:46 by zoum              #+#    #+#             */
/*   Updated: 2026/01/14 17:26:47 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <sys/time.h>
#include "PmergeMe.hpp"

double getTime() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000.0 + tv.tv_usec;
}

void printContainer(const std::vector<int>& container, const std::string& label) {
    std::cout << label;
    
    size_t limit = container.size() > 5 ? 5 : container.size();
    for (size_t i = 0; i < limit; i++) {
        std::cout << container[i];
        if (i < limit - 1)
            std::cout << " ";
    }
    
    if (container.size() > 5)
        std::cout << " [...]";
    
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    try {
        PmergeMe sorter;
        sorter.parseInput(argc, argv);

        // Display before sorting
        printContainer(sorter.getVector(), "Before: ");

        // Sort with vector and measure time
        double startVector = getTime();
        sorter.sortVector();
        double endVector = getTime();
        double timeVector = endVector - startVector;

        // Sort with deque and measure time
        double startDeque = getTime();
        sorter.sortDeque();
        double endDeque = getTime();
        double timeDeque = endDeque - startDeque;

        // Display after sorting
        printContainer(sorter.getVector(), "After:  ");

        // Display time results
        std::cout << std::fixed << std::setprecision(4);
        std::cout << "Time to process a range of " << sorter.getVector().size() 
                  << " elements with std::vector : " << timeVector / 1000.0 << " ms" << std::endl;
        std::cout << "Time to process a range of " << sorter.getDeque().size() 
                  << " elements with std::deque  : " << timeDeque / 1000.0 << " ms" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
