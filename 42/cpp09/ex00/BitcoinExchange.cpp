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

static void validate_line_format(const std::string& line)
{
	if ( line.length() < 14 ||
	!validate_date(line.substr(0, 10)) ||
	line.substr(10, 3) != " | ")
	{
		std::string err_str = "bad input => ";
		err_str.append(line);
		throw (std::runtime_error(err_str));
	}
}

static double get_double(const std::string& amount)
{
	std::istringstream iss(amount);
	double value;
	iss >> value;
	if (iss.fail() || !iss.eof() || value < 0)
		throw (std::runtime_error("not a positive number."));
	return (value);
}

void BitcoinExchange::reference_database(const std::string& line)
{
	std::string date = line.substr(0, 10);
	float amount = get_double(line.substr(13)); // here is your float
	if (amount > 1000)
		throw (std::runtime_error("too large a number."));

	std::map<std::string, double>::iterator match;

	match = m_c.lower_bound(date);

	if ((match == m_c.end() || match -> first != date) && match != m_c.begin())
		--match;
	std::cout << ICE_BLUE << date << " => " << amount << " = " << amount * match -> second << '\n';
}

void BitcoinExchange::exchange()
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
			validate_line_format(line);
			reference_database(line);
		}
		catch (const std::exception& e)
		{
			std::cerr << RED << "Error: " << e.what() << '\n' << END;
		}
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

	if (!file)
		throw std::runtime_error("could not read database.");

	while (std::getline(file, line))
	{
		comma_pos = line.find_first_of(',');
		if (comma_pos == std::string::npos  // no comma or more than one comma or whitespace
			|| comma_pos != line.find_last_of(',')
			|| line.find_first_of(" \t\r\v\f") != std::string::npos)
			throw std::runtime_error("invalid database format.");
		key = line.substr(0, comma_pos);
		value = line.substr(comma_pos + 1, std::string::npos);
		if (key == "" || value == "")
			throw std::runtime_error("invalid database format.");

		if (skip_header)
		{
			skip_header = false;
			continue;
		}

		if (!validate_date(key))
			throw std::runtime_error("invalid database format.");

		m_c.insert(std::make_pair(key, get_double(value)));
	}
}

void BitcoinExchange::dump_database()
{
	std::map<std::string, double>::iterator it;
	for (it = m_c.begin(); it != m_c.end(); ++it)
		std::cout << ICE_BLUE << "Key: " << it -> first << LIGHT_GREEN << " Value: " << it -> second << '\n' << END;
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