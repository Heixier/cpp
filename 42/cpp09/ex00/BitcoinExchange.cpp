#include <iostream>
#include <fstream>
#include <stdexcept>
#include <ctime>
#include <string>
#include <sstream>

#include "colors.hpp"
#include "BitcoinExchange.hpp"

#define DATABASE "data.csv"

static bool	ft_aredigits(const std::string& input) { return (input.find_first_not_of("0123456789") == std::string::npos ? true : false); }

static bool validate_date_format(const std::string& date)
{
	if (date.length() != 10)
		return (false);

	// Check separators
	if (date[4] != '-' || date[7] != '-')
		return (false);

	// Check YYYY
	std::string year = date.substr(0, 4);
	if (!ft_aredigits(year))
		return (false);

	// Check MM
	std::string month = date.substr(6, 2);
	if (!ft_aredigits(year))
		return (false);

	// Check DD
	std::string day = date.substr(8, 2);
	if (!ft_aredigits(year))
		return (false);

	return (true);
}

static bool validate_date(const std::string& date)
{
	if (!validate_date_format(date))
		return (false);

	std::tm tm;
	tm.tm_year = 42;
	// check date 

	return (true);
};

static bool validate_amount(const std::string& amount)
{
	std::istringstream iss(amount);
	float value;
	iss >> value;
	if (iss.fail() || !iss.eof())
		return (false);
	if (value < 0 || value > 1000)
		return (false);
	return (true);
}

static void validate_input_line(const std::string& line)
{
	if ( line.length() < 14 ||
	!validate_date(line.substr(0, 10)) ||
	line.substr(11, 3) != " | ")
	{
		std::string err_str = "bad input => ";
		err_str.append(line);
		throw (std::runtime_error(err_str));
	}
	std::string amount = line.substr(14, line.size());
	if (!ft_aredigits(amount))
		throw (std::runtime_error("not a positive number."));
	if (!validate_amount(amount))
		throw ("too large a number.");
}


void BitcoinExchange::reference_database()
{
	std::ifstream file(m_filename);
	std::string line;
	
	while (std::getline(file, line))
	{

	}
}

void BitcoinExchange::read_database()
{
	std::ifstream file(DATABASE);
	std::string line;
	size_t comma_pos;

	std::string key;
	std::string value;

	bool skip_header = true;

	if (!file.is_open())
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