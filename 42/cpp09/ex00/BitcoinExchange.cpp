#include <iostream>
#include <fstream>
#include <stdexcept>
#include "colors.hpp"

#include "BitcoinExchange.hpp"

#define DATABASE "data.csv"

void BitcoinExchange::dump_database()
{
	std::ifstream db(DATABASE);
	std::string line;
	while (std::getline(db, line))
	{
		std::cout << line << '\n';
	}
	db.close();
}

BitcoinExchange::BitcoinExchange()
{
	throw std::invalid_argument("No filename provided!");
}
BitcoinExchange::BitcoinExchange(const std::string& filename): m_database(DATABASE), m_filename(filename)
{
	std::ifstream file(m_filename.c_str());
	if (!file)
	{
		std::cout << RED << "Failed to open " << m_filename << " for reading!\n" << END;
		throw std::invalid_argument("Invalid file!");
	}
	file.close();
	
	std::ifstream db(DATABASE);
	if (!file)
	{
		std::cout << RED << "Failed to open " << m_filename << " for reading!\n" << END;
		throw std::invalid_argument("Invalid file!");
	}
	db.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other): m_filename(other.m_filename) { }

BitcoinExchange& BitcoinExchange::operator= (const BitcoinExchange& other)
{
	if (this != &other)
	{
		m_filename = other.m_filename;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() { }