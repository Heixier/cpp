#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		void	guardGate(void);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		const unsigned int&	get_attack(void) const;
		const unsigned int& get_health(void) const;

		ScavTrap(void);
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& scavtrap);
		ScavTrap& operator= (const ScavTrap& scavtrap);
		~ScavTrap(void);
};
