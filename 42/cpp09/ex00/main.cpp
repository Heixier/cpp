#include <iostream>
#include <exception>

#include "colors.hpp"
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << RED << "Invalid arguments! Provided: " << argc - 1 << " Expected: 2\n" << END;
		return (1);
	}
	try
	{
		BitcoinExchange btc(argv[1]);
		
		btc.dump_database();
	}
	catch (const std::exception& e)
	{
		std::cout << RED << e.what() << END;
	}

}