#include "ScavTrap.hpp"

void	ScavTrap::guardGate(void)
{
	if (this -> get_health() <= 0)
	{
		std::cout << RED << "FAILED: " << GREY << "ScavTrap " << m_name << " is dead!\n" << END;
		return ;
	}
	std::cout << GREY << m_name << " is now gatekeeping Serena, my love!\n" << END;
}

void	ScavTrap::attack(const std::string& target)
{
	if (m_hp <= 0)
	{
		std::cout << RED << "FAILED: " << GREY << "ScavTrap " << m_name << " is dead!\n" << END;
		return;
	}
	if (m_energy)
	{
		std::cout << GREY << "ScavTrap " << m_name << " throws rocks at " << target << " for " << m_damage << " damage!\n" << END;
		m_energy--;
		std::cout << GREY << m_name << END <<" has " << m_energy << " energy left!\n";
	}
	else
		std::cout << RED << "FAILED: " GREY << "ScavTrap " << m_name << " is out of energy!\n" << END;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (m_hp > 0)
	{
		if (amount < m_hp)
		{
			m_hp -= amount;
			std::cout << GREY << "ScavTrap " << m_name << " took " << amount << " damage!\n" << END;
			std::cout << GREY << "Health left: " << GREEN << m_hp << END << '\n';
		}
		else
		{
			m_hp = 0;
			std::cout << GREY << "Health left: " << RED << m_hp << END << '\n';
			std::cout << GREY << "ScavTrap " << m_name << RED << " has died!\n" << END;
		}
	}
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (m_hp > 0)
	{
		if (m_energy)
			m_energy--;
		else
		{
			std::cout << RED << "FAILED: " << GREY << "ScavTrap " << m_name << " is out of energy!\n" << END;
			return ;
		}
		m_hp += amount;
		std::cout << GREY << "ScavTrap " << m_name << " was repaired for " << GREEN << amount << " health!\n" << END;
		std::cout << GREY << "Health: " << GREEN << m_hp << END << '\n';
		std::cout << GREY << m_name << END <<" has " << m_energy << " energy left!\n";
	}
	else
		std::cout << RED << "FAILED: " << GREY << "ScavTrap " << m_name << " is dead!\n" << END;
}

const unsigned int&	ScavTrap::get_attack(void) const { return (m_damage); }
const unsigned int&	ScavTrap::get_health(void) const { return (m_hp); }

ScavTrap::ScavTrap(void) : ClapTrap()
{
	m_hp = 100;
	m_energy = 50;
	m_damage = 20;
	std::cout << GREY << "Scavtrap " << m_name << " has been spawned!\nHP: " << m_hp << "\nEnergy: " << m_energy << "\nDamage: " << m_damage << END << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	m_hp = 100;
	m_energy = 50;
	m_damage = 20;
	std::cout << GREY << "Scavtrap " << m_name << " has been spawned!\nHP: " << m_hp << "\nEnergy: " << m_energy << "\nDamage: " << m_damage << END << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavtrap) : ClapTrap(scavtrap) { }

ScavTrap& ScavTrap::operator= (const ScavTrap& scavtrap)
{
	if (this != &scavtrap)
		ClapTrap::operator=(scavtrap);
	return (*this);
}

ScavTrap::~ScavTrap(void) { std::cout << GREY << "Scavtrap " << m_name << " has been destroyed!\n" << END;  }