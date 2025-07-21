#include "Harl.hpp"

static size_t	get_element(std::string element)
{
	const std::string	array[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (size_t i = 0; i < (sizeof(array)/sizeof(array[0])); i++)
	{
		if (element == array[i])
			return (i);
	}
	return (-1);
}

void	Harl::complain(std::string level) const
{
	size_t	element = get_element(level);

	switch(element)
	{
		case __SIZE_MAX__:
			std::cout << "\e[38;5;242;1m[ grumpy noises ]\e[0m\n";
			break;
		case 0:
			debug();
			// fallthrough
		case 1:
			info();
			// fall through
		case 2:
			warning();
			// FALL THROUGH
		case 3:
			error();
			// FALLTHROUGH
		default:
			break;
	}
}

void	Harl::debug(void) const { std::cout << "\e[38;5;117;1m[ DEBUG ]\nwah ERP so expensive now lah last time fifty cents only now six dollar how like that\e[0m\n\n"; }
void	Harl::info(void) const { std::cout << "\e[38;5;226;1m[ INFO ]\nthis bmw driver no signal just cut in front of me stupid or what make me brake so hard my kopi nearly spill\e[0m\n\n"; }
void	Harl::warning(void) const { std::cout << "\e[38;5;208;1m[ WARNING ]\nCOE 100k now just for paper only haven even buy car yet damn stupid sia how ppl afford?\e[0m\n\n"; }
void	Harl::error(void) const { std::cout << "\e[38;5;196;1m[ ERROR ]\nwalao this grab driver cut three lanes nearly hit my car want to call TP report him this kind idiot shouldnt have license\e[0m\n\n"; }

Harl::Harl(void) { }
Harl::~Harl(void) { }