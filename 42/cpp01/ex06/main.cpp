#include "Harl.hpp"

#include "Harl.hpp"
#include <cstdlib>
#include <ctime>

int main(int argc, char **argv)
{
	Harl	harl;

	if (argc != 2)
	{
		std::cout << "Unexpected number of arguments!\n";
		return (1);
	}

	harl.complain(argv[1]);
}
