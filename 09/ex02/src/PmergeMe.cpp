/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:11:51 by zoum              #+#    #+#             */
/*   Updated: 2026/01/14 17:11:52 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <cmath>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

const char* PmergeMe::InvalidInputException::what() const throw() {
    return "Error";
}

void PmergeMe::parseInput(int argc, char** argv) {
    if (argc < 2)
        throw InvalidInputException();

    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        
        if (arg.empty())
            throw InvalidInputException();
        
        for (size_t j = 0; j < arg.length(); j++) {
            if (!std::isdigit(arg[j]))
                throw InvalidInputException();
        }
        
        char* end;
        long num = std::strtol(arg.c_str(), &end, 10);
        
        if (*end != '\0' || num < 0 || num > 2147483647)
            throw InvalidInputException();
        
        _vectorData.push_back(static_cast<int>(num));
        _dequeData.push_back(static_cast<int>(num));
    }
}

template<typename Container>
void PmergeMe::insertionSort(Container& arr, size_t left, size_t right) {
    for (size_t i = left + 1; i <= right; i++) {
        typename Container::value_type key = arr[i];
        size_t j = i;
        
        while (j > left && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}

template<typename Container>
void PmergeMe::merge(Container& arr, size_t left, size_t mid, size_t right) {
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;
    
    Container leftArr(arr.begin() + left, arr.begin() + mid + 1);
    Container rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);
    
    size_t i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

std::vector<int> PmergeMe::generateJacobsthalSequence(size_t n) {
    std::vector<int> jacobsthal;
    
    if (n == 0)
        return jacobsthal;
    
    jacobsthal.push_back(0);
    if (n == 1)
        return jacobsthal;
    
    jacobsthal.push_back(1);
    
    while (true) {
        size_t next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        if (next >= n)
            break;
        jacobsthal.push_back(next);
    }
    
    return jacobsthal;
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& arr) {
    size_t n = arr.size();
    
    if (n <= 1)
        return;
    
    // Use insertion sort for small arrays
    if (n <= 16) {
        insertionSort(arr, 0, n - 1);
        return;
    }
    
    // Create pairs and sort them
    std::vector<std::pair<int, int> > pairs;
    bool hasStraggler = (n % 2 == 1);
    int straggler = hasStraggler ? arr[n - 1] : 0;
    
    for (size_t i = 0; i < n - (hasStraggler ? 1 : 0); i += 2) {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }
    
    // Sort pairs by their larger element
    for (size_t i = 1; i < pairs.size(); i++) {
        std::pair<int, int> key = pairs[i];
        size_t j = i;
        
        while (j > 0 && pairs[j - 1].first > key.first) {
            pairs[j] = pairs[j - 1];
            j--;
        }
        pairs[j] = key;
    }
    
    // Build main chain and pending elements
    std::vector<int> mainChain;
    std::vector<int> pending;
    
    for (size_t i = 0; i < pairs.size(); i++) {
        mainChain.push_back(pairs[i].first);
        pending.push_back(pairs[i].second);
    }
    
    if (hasStraggler)
        pending.push_back(straggler);
    
    // Insert pending elements using binary search
    for (size_t i = 0; i < pending.size(); i++) {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pending[i]);
        mainChain.insert(pos, pending[i]);
    }
    
    arr = mainChain;
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr) {
    size_t n = arr.size();
    
    if (n <= 1)
        return;
    
    // Use insertion sort for small arrays
    if (n <= 16) {
        insertionSort(arr, 0, n - 1);
        return;
    }
    
    // Create pairs and sort them
    std::deque<std::pair<int, int> > pairs;
    bool hasStraggler = (n % 2 == 1);
    int straggler = hasStraggler ? arr[n - 1] : 0;
    
    for (size_t i = 0; i < n - (hasStraggler ? 1 : 0); i += 2) {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }
    
    // Sort pairs by their larger element
    for (size_t i = 1; i < pairs.size(); i++) {
        std::pair<int, int> key = pairs[i];
        size_t j = i;
        
        while (j > 0 && pairs[j - 1].first > key.first) {
            pairs[j] = pairs[j - 1];
            j--;
        }
        pairs[j] = key;
    }
    
    // Build main chain and pending elements
    std::deque<int> mainChain;
    std::deque<int> pending;
    
    for (size_t i = 0; i < pairs.size(); i++) {
        mainChain.push_back(pairs[i].first);
        pending.push_back(pairs[i].second);
    }
    
    if (hasStraggler)
        pending.push_back(straggler);
    
    // Insert pending elements using binary search
    for (size_t i = 0; i < pending.size(); i++) {
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pending[i]);
        mainChain.insert(pos, pending[i]);
    }
    
    arr = mainChain;
}

void PmergeMe::sortVector() {
    mergeInsertSortVector(_vectorData);
}

void PmergeMe::sortDeque() {
    mergeInsertSortDeque(_dequeData);
}

const std::vector<int>& PmergeMe::getVector() const {
    return _vectorData;
}

const std::deque<int>& PmergeMe::getDeque() const {
    return _dequeData;
}
