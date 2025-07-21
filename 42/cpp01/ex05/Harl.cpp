#include "Harl.hpp"


void	Harl::complain(std::string level) const
{
	static const std::string anger[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	static void (Harl::*complaints[4])(void) const = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
	};
	for (int i = 0; i < 4; i++)
	{
		if (level == anger[i])
		{
			(this->*complaints[i])();
			return ;
		}
	}
	std::cout << "\e[38;5;242;1msleeping noises\e[0m\n";
}

void	Harl::debug(void) const { std::cout << "\e[38;5;117;1mwah ERP so expensive now lah last time fifty cents only now six dollar how like that\e[0m\n"; }
void	Harl::info(void) const { std::cout << "\e[38;5;226;1mthis bmw driver no signal just cut in front of me stupid or what make me brake so hard my kopi nearly spill\e[0m\n"; }
void	Harl::warning(void) const { std::cout << "\e[38;5;208;1mCOE 100k now just for paper only haven even buy car yet damn stupid sia how ppl afford?\e[0m\n"; }
void	Harl::error(void) const { std::cout << "\e[38;5;196;1mwalao this grab driver cut three lanes nearly hit my car want to call TP report him this kind idiot shouldnt have license\e[0m\n"; }

Harl::Harl(void) { }
Harl::~Harl(void) { }