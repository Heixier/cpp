#include <iostream>
#include <exception>

#include "colors.hpp"
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		try
		{
			BitcoinExchange btc;
		}
		catch (const std::exception& e)
		{
			std::cerr << RED << "Error: " << e.what() << '\n' << END;
		}
		return (1);
	}
	try
	{
		BitcoinExchange btc(argv[1]);
		btc.reference_database();
		// btc.dump_database(); // temp just dump database to demonstrate and ignore input
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Error: " << e.what() << '\n' << END;
	}
}