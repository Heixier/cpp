#include "ScavTrap.hpp"

void	ScavTrap::guardGate(void) { std::cout << GREY << m_name << " is now a gatekeeper. Serena, my love!\n" << END; }

void	ScavTrap::attack(const std::string& target)
{
	if (m_hp <= 0)
	{
		std::cout << GREY << "ScavTrap " << m_name << " is dead!\n" << END;
		return;
	}
	if (m_energy)
	{
		std::cout << GREY << "ScavTrap " << m_name << " throws rocks at " << target << " for " << m_damage << " damage!\n" << END;
		m_energy--;
		std::cout << m_name << " has " << m_energy << " energy left!\n";
	}
	else
		std::cout << RED << "FAILED: " YELLOW << "ScavTrap " << m_name << " is out of energy!\n" << END;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (m_hp > 0)
	{
		if (amount < m_hp)
			m_hp -= amount;
		else
			m_hp = 0;
		std::cout << GREY << "ScavTrap " << m_name << " took " << amount << " damage!\n" << END;
		std::cout << "Health left: " << m_hp << '\n';
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
			std::cout << GREY << "ScavTrap " << m_name << " is out of energy!\n" << END;
			return ;
		}
		m_hp += amount;
		std::cout << GREY << "ScavTrap " << m_name << " was repaired for " << amount << " health!\n" << END;
		std::cout << "Health left: " << m_hp << '\n';
		std::cout << m_name << " has " << m_energy << " energy left!\n";
	}
	else
		std::cout << RED << "FAILED: " << GREY << "ScavTrap " << m_name << " is dead!\n" << END;
}

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

ScavTrap::~ScavTrap(void) { std::cout << GREY << "Scavtrap " << m_name << " has been destroyed!\n"; }