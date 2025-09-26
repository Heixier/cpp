#include <iostream>
#include <fstream>
#include <stdexcept>
#include "colors.hpp"

#include "BitcoinExchange.hpp"

#define DATABASE "data.csv"

void BitcoinExchange::validate_database()
{
	std::ifstream file(DATABASE);
	std::string line;
	size_t comma_pos;

	std::string key;
	std::string value;

	bool skip_header = true;

	if (!file.is_open())
		throw std::runtime_error("Cannot open database for reading!");

	while (std::getline(file, line))
	{
		comma_pos = line.find_first_of(',');
		if (comma_pos == std::string::npos  // no comma or more than one comma or whitespace
			|| comma_pos != line.find_last_of(',')
			|| line.find_first_of(" \t\r\v\f") != std::string::npos)
		{
			file.close();
			throw std::runtime_error("Database format error!");
		}
		try
		{
			key = line.substr(0, comma_pos);
			value = line.substr(comma_pos + 1, std::string::npos);
			if (key == "" || value == "")
			{
				file.close();
				throw std::runtime_error("Database format error!");
			}
		}
		catch (...)
		{
			file.close();
			throw;
		}
		if (skip_header)
		{
			skip_header = false;
			continue;
		}
		m_c.insert(std::make_pair(key, value));
	}
	file.close();
}

void BitcoinExchange::dump_database()
{
	std::map<std::string, std::string>::iterator it;
	for (it = m_c.begin(); it != m_c.end(); ++it)
	{
		std::cout << ICE_BLUE << "Key: " << it -> first << LIGHT_GREEN << " Value: " << it -> second << '\n' << END;
	}
}

BitcoinExchange::BitcoinExchange()
{
	throw std::invalid_argument("No filename provided!");
}
BitcoinExchange::BitcoinExchange(const std::string& filename): m_filename(filename)
{
	std::ifstream file(m_filename.c_str());
	if (!file)
	{
		std::cerr << RED << "Failed to open " << m_filename << " for reading!\n" << END;
		throw std::invalid_argument("File read error!");
	}
	file.close();
	validate_database();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other): m_c(other.m_c), m_filename(other.m_filename) { }

BitcoinExchange& BitcoinExchange::operator= (const BitcoinExchange& other)
{
	if (this != &other)
	{
		m_c = other.m_c;
		m_filename = other.m_filename;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() { }