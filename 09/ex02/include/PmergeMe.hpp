/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:11:40 by zoum              #+#    #+#             */
/*   Updated: 2026/01/14 17:11:41 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <exception>

class PmergeMe {
private:
    std::vector<int> _vectorData;
    std::deque<int> _dequeData;

    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);

    // Ford-Johnson algorithm for vector
    void mergeInsertSortVector(std::vector<int>& arr);
    std::vector<int> generateJacobsthalSequence(size_t n);
    
    // Ford-Johnson algorithm for deque
    void mergeInsertSortDeque(std::deque<int>& arr);

    // Helper functions
    template<typename Container>
    void insertionSort(Container& arr, size_t left, size_t right);
    
    template<typename Container>
    void merge(Container& arr, size_t left, size_t mid, size_t right);

public:
    PmergeMe();
    ~PmergeMe();

    void parseInput(int argc, char** argv);
    void sortVector();
    void sortDeque();
    
    const std::vector<int>& getVector() const;
    const std::deque<int>& getDeque() const;

    class InvalidInputException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

#endif
