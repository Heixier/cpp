#include "ClapTrap.hpp"

void	ClapTrap::attack(const std::string& target)
{
	if (m_hp <= 0)
	{
		std::cout << YELLOW << "ClapTrap " << m_name << " is dead!\n" << END;
		return;
	}
	if (m_energy)
	{
		std::cout << YELLOW << "ClapTrap " << m_name << " attacks " << target << " for " << m_damage << " damage!\n" << END;
		m_energy--;
		std::cout << m_name << " has " << m_energy << " energy left!\n";
	}
	else
		std::cout << RED << "FAILED: " YELLOW << "ClapTrap " << m_name << " is out of energy!\n" << END;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (m_hp > 0)
	{
		if (amount < m_hp)
			m_hp -= amount;
		else
			m_hp = 0;
		std::cout << YELLOW << "ClapTrap " << m_name << " took " << amount << " damage!\n" << END;
		std::cout << "Health left: " << m_hp << '\n';
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (m_hp > 0)
	{
		if (m_energy)
			m_energy--;
		else
		{
			std::cout << YELLOW << "ClapTrap " << m_name << " is out of energy!\n" << END;
			return ;
		}
		m_hp += amount;
		std::cout << YELLOW << "ClapTrap " << m_name << " was repaired for " << amount << " health!\n" << END;
		std::cout << "Health left: " << m_hp << '\n';
		std::cout << m_name << " has " << m_energy << " energy left!\n";
	}
	else
		std::cout << RED << "FAILED: " << YELLOW << "ClapTrap " << m_name << " is dead!\n" << END;
}

ClapTrap::ClapTrap(void) : m_name("Clappy"), m_hp(10), m_energy(10), m_damage(10)
{
	std::cout << YELLOW << "ClapTrap " << m_name << " has spawned!\nHP: " << m_hp << "\nEnergy: " << m_energy << "\nDamage: " << m_damage << END << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : m_name(name), m_hp(10), m_energy(10), m_damage(0)
{
	std::cout << YELLOW << "ClapTrap " << m_name << " has spawned!\nHP: " << m_hp << "\nEnergy: " << m_energy << "\nDamage: " << m_damage << END << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy) { *this = copy; }
ClapTrap& ClapTrap::operator= (const ClapTrap& copy)
{
	if (this != &copy)
	{
		m_name = copy.m_name;
		m_hp = copy.m_hp;
		m_energy = copy.m_energy;
		m_damage = copy.m_damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void) { std::cout << YELLOW << "Claptrap " << m_name << " has been destroyed!\n"; }
