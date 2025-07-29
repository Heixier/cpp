#include <iostream>

#define YELLOW "\e[38;5;178;1m"
#define RED "\e[38;5;160;1m"
#define BLUE "\e[38;5;117;1m"
#define GREY "\e[38;5;248;1m"
#define END "\e[0m"

class ClapTrap
{
	public:
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap& copy);
		ClapTrap& operator= (const ClapTrap& copy);
		~ClapTrap(void);

	protected:
		std::string m_name;
		unsigned int	m_hp;
		unsigned int	m_energy;
		unsigned int	m_damage;
};