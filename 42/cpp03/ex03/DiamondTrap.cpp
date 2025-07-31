#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap()
{
	m_hp = FragTrap::m_hp;
	m_damage = FragTrap::m_damage;
	m_energy = ScavTrap::m_energy;
}