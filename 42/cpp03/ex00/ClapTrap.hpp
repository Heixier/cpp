#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <limits.h>

#define YELLOW "\e[38;5;178;1m"
#define GREEN "\e[38;5;36;1m"
#define RED "\e[38;5;160;1m"
#define ORANGE "\e[38;5;208;1m"
#define BLUE "\e[38;5;117;1m"
#define GREY "\e[38;5;248;1m"
#define END "\e[0m"

class ClapTrap
{
	public:
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		const unsigned int&	get_attack(void) const;
		const unsigned int&	get_health(void) const;
		const unsigned int&	get_energy(void) const;
		const std::string& p_get_name(void) const;

		ClapTrap(void);
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& copy);
		ClapTrap& operator= (const ClapTrap& copy);
		~ClapTrap(void);

	protected:
		virtual const std::string& get_name(void) const;
		std::string 	m_name;
		unsigned int	m_hp;
		unsigned int	m_energy;
		unsigned int	m_damage;
};

#endif