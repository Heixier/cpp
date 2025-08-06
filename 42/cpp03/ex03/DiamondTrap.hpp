#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
	public:
		void	whoAmI(void);

		const unsigned int&	get_attack(void) const;
		const unsigned int&	get_health(void) const;
		const unsigned int&	get_energy(void) const;

		DiamondTrap(void);
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap& operator= (const DiamondTrap& other);
		~DiamondTrap(void);

	protected:
		virtual const std::string& get_name(void) const;
		
	private:
		std::string	m_name;
};

#endif