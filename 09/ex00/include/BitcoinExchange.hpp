/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:38:40 by zoum              #+#    #+#             */
/*   Updated: 2026/01/14 16:38:41 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <exception>

class BitcoinExchange {
private:
    std::map<std::string, double> _database;

    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);

    bool isValidDate(const std::string& date) const;
    bool isValidValue(const std::string& value) const;
    double stringToDouble(const std::string& str) const;
    std::string trim(const std::string& str) const;
    std::string findClosestDate(const std::string& date) const;

public:
    BitcoinExchange();
    ~BitcoinExchange();

    void loadDatabase(const std::string& filename);
    void processInputFile(const std::string& filename);

    class FileOpenException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class InvalidDatabaseException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

#endif
