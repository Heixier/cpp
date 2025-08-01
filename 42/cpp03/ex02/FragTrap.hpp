#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap: public virtual ClapTrap
{
	public:
		void	highFiveGuys(void);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		FragTrap(void);
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& other);
		FragTrap& operator= (const FragTrap& other);
		~FragTrap(void);

	protected:
		static const unsigned int hp = 100;
		static const unsigned int energy = 100;
		static const unsigned int damage = 30;
};

#endif