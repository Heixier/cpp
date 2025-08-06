#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
	public:
		void	guardGate(void);
		void	attack(const std::string& target);

		ScavTrap(void);
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& scavtrap);
		ScavTrap& operator= (const ScavTrap& scavtrap);
		~ScavTrap(void);

	protected:
		static const unsigned int hp = 100;
		static const unsigned int energy = 50;
		static const unsigned int damage = 20;
};

#endif