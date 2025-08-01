#include "ScavTrap.hpp"

void	ScavTrap::guardGate(void)
{
	if (this -> get_health() <= 0)
	{
		std::cout << RED << "FAILED: " << GREY << "ScavTrap " << get_name() << " is dead!\n" << END;
		return ;
	}
	std::cout << GREY << get_name() << " is now gatekeeping Serena, my love!\n" << END;
}

void	ScavTrap::attack(const std::string& target)
{
	if (m_hp <= 0)
	{
		std::cout << RED << "FAILED: " << GREY << "ScavTrap " << get_name() << " is dead!\n" << END;
		return;
	}
	if (m_energy)
	{
		std::cout << GREY << "ScavTrap " << get_name() << " throws rocks at " << target << " for " << m_damage << " damage!\n" << END;
		m_energy--;
		std::cout << GREY << get_name() << END <<" has " << m_energy << " energy left!\n";
	}
	else
		std::cout << RED << "FAILED: " GREY << "ScavTrap " << get_name() << " is out of energy!\n" << END;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (m_hp > 0)
	{
		if (amount < m_hp)
		{
			m_hp -= amount;
			std::cout << GREY << "ScavTrap " << get_name() << " took " << amount << " damage!\n" << END;
			std::cout << GREY << "Health left: " << GREEN << m_hp << END << '\n';
		}
		else
		{
			m_hp = 0;
			std::cout << GREY << "Health left: " << RED << m_hp << END << '\n';
			std::cout << GREY << "ScavTrap " << get_name() << RED << " has died!\n" << END;
		}
	}
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	unsigned long long	result = static_cast<unsigned long long>(amount) + static_cast<unsigned long long>(m_hp);

	if (m_hp > 0)
	{
		if (m_energy)
			m_energy--;
		else
		{
			std::cout << RED << "FAILED: " << GREY << "ScavTrap " << get_name() << " is out of energy!\n" << END;
			return ;
		}
		if (result >= UINT_MAX)
			m_hp = UINT_MAX;
		else
			m_hp += amount;
		std::cout << GREY << "ScavTrap " << get_name() << " was repaired for " << GREEN << amount << " health!\n" << END;
		std::cout << GREY << "Health: " << GREEN << m_hp << END << '\n';
		std::cout << GREY << get_name() << END <<" has " << m_energy << " energy left!\n";
	}
	else
		std::cout << RED << "FAILED: " << GREY << "ScavTrap " << get_name() << " is dead!\n" << END;
}

ScavTrap::ScavTrap(void) : ClapTrap()
{
	m_hp = hp;
	m_energy = energy;
	m_damage = damage;
	std::cout << GREY << "Scavtrap " << get_name() << " has spawned!\nHP: " << m_hp << "\nEnergy: " << m_energy << "\nDamage: " << m_damage << END << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	m_hp = hp;
	m_energy = energy;
	m_damage = damage;
	std::cout << GREY << "Scavtrap " << get_name() << " has spawned!\nHP: " << m_hp << "\nEnergy: " << m_energy << "\nDamage: " << m_damage << END << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) { std::cout << GREY << "ScavTrap " << other.m_name << " has been copied!" << END << std::endl; }

ScavTrap& ScavTrap::operator= (const ScavTrap& other)
{
	std::cout << GREY << "ScavTrap : " << other.m_name << " has been copy assigned!" << END << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

ScavTrap::~ScavTrap(void) { std::cout << GREY << "Scavtrap " << get_name() << " has been destroyed!\n" << END;  }