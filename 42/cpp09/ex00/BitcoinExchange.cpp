#include <iostream>
#include <fstream>
#include <stdexcept>
#include <ctime>
#include <string>
#include <sstream>
#include <cstdlib>


#include "colors.hpp"
#include "BitcoinExchange.hpp"

#define DATABASE "data.csv"

static bool validate_date(const std::string& date)
{

	std::tm tm = {};
	const char * result = strptime(date.c_str(), "%Y-%m-%d", &tm);
	if (!result || *result != '\0')
		return (false);

	int year = tm.tm_year;
	int month = tm.tm_mon;
	int day = tm.tm_mday;

	std::time_t t = std::mktime(&tm);
	return (t != -1 &&
		tm.tm_year == year &&
		tm.tm_mon == month &&
		tm.tm_mday == day);
};

static void validate_amount(const std::string& amount)
{
	std::istringstream iss(amount);
	float value;
	iss >> value;
	if (iss.fail() || !iss.eof() || value < 0)
		throw (std::runtime_error("not a positive number."));
	if (value > 1000)
		throw (std::runtime_error("too large a number."));
}

static void validate_input_line(const std::string& line)
{
	if ( line.length() < 14 ||
	!validate_date(line.substr(0, 10)) ||
	line.substr(10, 3) != " | ")
	{
		std::string err_str = "bad input => ";
		err_str.append(line);
		throw (std::runtime_error(err_str));
	}
	validate_amount(line.substr(13));
}

void BitcoinExchange::reference_database()
{
	std::ifstream file(m_filename.c_str());
	std::string line;
	bool skip_header = true;
	
	while (std::getline(file, line))
	{
		if (skip_header)
		{
			skip_header = false;
			continue;
		}
		try
		{
			validate_input_line(line);
			std::cout << LIGHT_GREEN << "Line: " << line << '\n' << END;
		}
		catch (const std::exception& e)
		{
			std::cout << RED << "Error: " << e.what() << '\n' << END;
		}
	}
	file.close();
}

void BitcoinExchange::read_database()
{
	std::ifstream file(DATABASE);
	std::string line;
	size_t comma_pos;

	std::string key;
	std::string value;

	bool skip_header = true;

	if (!file)
		throw std::runtime_error("could not read database.");

	while (std::getline(file, line))
	{
		comma_pos = line.find_first_of(',');
		if (comma_pos == std::string::npos  // no comma or more than one comma or whitespace
			|| comma_pos != line.find_last_of(',')
			|| line.find_first_of(" \t\r\v\f") != std::string::npos)
		{
			file.close();
			throw std::runtime_error("invalid database format.");
		}
		try
		{
			key = line.substr(0, comma_pos);
			value = line.substr(comma_pos + 1, std::string::npos);
			if (key == "" || value == "")
			{
				file.close();
				throw std::runtime_error("invalid database format.");
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
	throw std::invalid_argument("could not open file.");
}
BitcoinExchange::BitcoinExchange(const std::string& filename): m_filename(filename)
{
	std::ifstream file(m_filename.c_str());
	if (!file)
		throw std::invalid_argument("could not open file.");
	file.close();
	read_database();
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