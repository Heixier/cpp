#include "DiamondTrap.hpp"

void	DiamondTrap::whoAmI(void)
{
	if (m_hp == 0)
	{
		std::cout << RED << "FAILED: " << BLUE << "DiamondTrap " << get_name() << " is dead!\n" << END;
		return;
	}
	std::cout << BLUE << "Name: " << std::right << std::setw(8) << get_name() << YELLOW << "\nClap name: " << std::right << std::setw(8) << ClapTrap::m_name<< END << std::endl;
}

const unsigned int&	DiamondTrap::get_attack(void) const { return (m_damage); }
const unsigned int&	DiamondTrap::get_health(void) const { return (m_hp); }
const unsigned int&	DiamondTrap::get_energy(void) const { return (m_energy); }
const std::string& DiamondTrap::get_name(void) const { return (m_name); }

DiamondTrap::DiamondTrap(void) : ClapTrap("Diamond_clap_name")
{
	m_name = "Diamond";
	m_hp = FragTrap::hp;
	m_energy = ScavTrap::energy;
	m_damage = FragTrap::damage;
	std::cout << BLUE << "DiamondTrap " << get_name() << " has spawned!\nHP: " << m_hp << "\nEnergy: " << m_energy << "\nDamage: " << m_damage << END << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name")
{
	m_name = name;
	m_hp = FragTrap::hp;
	m_energy = ScavTrap::energy;
	m_damage = FragTrap::damage;
	std::cout << BLUE << "DiamondTrap " << get_name() << " has spawned!\nHP: " << m_hp << "\nEnergy: " << m_energy << "\nDamage: " << m_damage << END << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	m_name = other.m_name;
	m_hp = other.m_hp;
	m_energy = other.m_energy;
	m_damage = other.m_damage;
	std::cout << BLUE << "DiamondTrap " << other.m_name << " has been copied!" << END << std::endl;
}

DiamondTrap& DiamondTrap::operator= (const DiamondTrap& other)
{
	std::cout << BLUE << "DiamondTrap " << other.m_name << " has been copy assigned!" << END << std::endl;
	if (this != &other)
	{
		m_name = other.m_name;
		m_hp = other.m_hp;
		m_energy = other.m_energy;
		m_damage = other.m_damage;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void) { std::cout << BLUE << "DiamondTrap " << get_name() << " has been destroyed!\n" << END;  }
