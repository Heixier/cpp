#include "Harl.hpp"

#include "Harl.hpp"
#include <cstdlib>
#include <ctime>

int main(void)
{
	Harl	harl;
	const std::string levels[5] = {"DEBUG", "INFO", "WARNING", "ERROR", "SLEEP"};
	
	std::srand(std::time(0));
	for (int i = 0; i < (std::rand() % 10) + 4; i++)
		harl.complain(levels[std::rand() % (sizeof(levels)/sizeof(levels[0]))]);

	// harl.complain("DEBUG");
	// harl.complain("INFO");
	// harl.complain("WARNING");
	// harl.complain("ERROR");
}