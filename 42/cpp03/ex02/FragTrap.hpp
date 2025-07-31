#include <iostream>
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		void	highFiveGuys(void);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		const unsigned int&	get_attack(void) const;
		const unsigned int&	get_health(void) const;

		FragTrap(void);
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& fragtrap);
		FragTrap& operator= (const FragTrap& fragtrap);
		~FragTrap(void);
};