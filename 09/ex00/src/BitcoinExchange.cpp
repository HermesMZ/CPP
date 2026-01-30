/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:38:25 by zoum              #+#    #+#             */
/*   Updated: 2026/01/14 16:38:26 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <algorithm>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

const char* BitcoinExchange::FileOpenException::what() const throw() {
    return "Error: could not open file.";
}

const char* BitcoinExchange::InvalidDatabaseException::what() const throw() {
    return "Error: invalid database format.";
}

std::string BitcoinExchange::trim(const std::string& str) const {
    size_t start = str.find_first_not_of(" \t\r\n");
    size_t end = str.find_last_not_of(" \t\r\n");
    
    if (start == std::string::npos)
        return "";
    
    return str.substr(start, end - start + 1);
}

double BitcoinExchange::stringToDouble(const std::string& str) const {
    char* end;
    double value = std::strtod(str.c_str(), &end);
    
    if (*end != '\0' && *end != '\n')
        return -1;
    
    return value;
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 10)
        return false;
    
    if (date[4] != '-' || date[7] != '-')
        return false;
    
    for (size_t i = 0; i < date.length(); i++) {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }
    
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    
    if (month == 2) {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (isLeap ? 29 : 28))
            return false;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30)
            return false;
    }
    
    return true;
}

bool BitcoinExchange::isValidValue(const std::string& value) const {
    if (value.empty())
        return false;
    
    size_t start = 0;
    if (value[0] == '-' || value[0] == '+')
        start = 1;
    
    bool hasDot = false;
    for (size_t i = start; i < value.length(); i++) {
        if (value[i] == '.') {
            if (hasDot)
                return false;
            hasDot = true;
        } else if (!std::isdigit(value[i])) {
            return false;
        }
    }
    
    return true;
}

void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    
    if (!file.is_open())
        throw FileOpenException();
    
    std::string line;
    std::getline(file, line); // Skip header
    
    while (std::getline(file, line)) {
        size_t pos = line.find(',');
        if (pos == std::string::npos)
            continue;
        
        std::string date = trim(line.substr(0, pos));
        std::string value_str = trim(line.substr(pos + 1));
        
        if (!isValidDate(date))
            continue;
        
        double value = stringToDouble(value_str);
        if (value < 0)
            continue;
        
        _database[date] = value;
    }
    
    file.close();
    
    if (_database.empty())
        throw InvalidDatabaseException();
}

std::string BitcoinExchange::findClosestDate(const std::string& date) const {
    std::map<std::string, double>::const_iterator it = _database.lower_bound(date);
    
    if (it == _database.begin()) {
        if (it->first == date)
            return it->first;
        return "";
    }
    
    if (it != _database.end() && it->first == date)
        return it->first;
    
    --it;
    return it->first;
}

void BitcoinExchange::processInputFile(const std::string& filename) {
    std::ifstream file(filename.c_str());
    
    if (!file.is_open())
        throw FileOpenException();
    
    std::string line;
    std::getline(file, line); // Skip header
    
    while (std::getline(file, line)) {
        size_t pos = line.find('|');
        
        if (pos == std::string::npos) {
            std::cout << "Error: bad input => " << trim(line) << std::endl;
            continue;
        }
        
        std::string date = trim(line.substr(0, pos));
        std::string value_str = trim(line.substr(pos + 1));
        
        if (!isValidDate(date)) {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        
        if (!isValidValue(value_str)) {
            std::cout << "Error: bad input => " << value_str << std::endl;
            continue;
        }
        
        double value = stringToDouble(value_str);
        
        if (value < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        
        if (value > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
        
        std::string closestDate = findClosestDate(date);
        
        if (closestDate.empty()) {
            std::cout << "Error: no data available for date => " << date << std::endl;
            continue;
        }
        
        double rate = _database.find(closestDate)->second;
        double result = value * rate;
        
        std::cout << date << " => " << value << " = " << result << std::endl;
    }
    
    file.close();
}
