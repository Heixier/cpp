#include <iostream>
#include <exception>

#include "colors.hpp"
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << RED << "Invalid arguments! Provided: " << argc - 1 << " Expected: 1\n" << END;
		return (1);
	}
	try
	{
		BitcoinExchange btc(argv[1]);
		
		btc.dump_database(); // temp just dump database to demonstrate and ignore input
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << '\n' << END;
	}

}