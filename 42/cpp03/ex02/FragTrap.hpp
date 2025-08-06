#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		void	highFiveGuys(void);

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