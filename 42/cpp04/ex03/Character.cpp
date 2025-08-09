#include "Character.hpp"

std::string const & Character::getName() const { return m_name; }

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!m_inventory[i])
		{
			if (!m)
			{
				std::cout << "Equipped literally nothing at slot " << i << "!\n";
				return;
			}
			m_inventory[i] = m;
			std::cout << "Equipped " << m_inventory[i] -> getType() << " at slot " << i << "!\n";
			return;
		}
	}
	if (m)
	{
		std::cout << "Failed to equip " << m -> getType() << ". No slots left! Materia has been lost...\n";
		delete m;
		m = NULL;
	}
	else
		std::cout << "Failed to equip literally nothing (yes this still needs slots). No slots left!\n";
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << idx << " is out of range!";
		return;
	}
	std::cout << "Unequipping " << m_inventory[idx] -> getType() << "!\n";
	m_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << idx << " is out of range!\n";
		return;
	}
	if (!m_inventory[idx])
	{
		std::cout << "Nothing equipped at " << idx << "!\n";
		return;
	}
	m_inventory[idx] -> use(target);
}

Character::Character(void): m_name("Bob")
{
	std::cout << m_name << " has been created!\n";
	for (int i = 0; i < 4; i++)
		m_inventory[i] = NULL;
}

Character::Character(const std::string& name): m_name(name)
{
	for (int i = 0; i < 4; i++)
		m_inventory[i] = NULL;
	std::cout << m_name << " has been created!\n";
}

Character::Character(const Character& other): m_name(other.getName())
{
	for (int i =0; i < 4; i++)
	{
		m_inventory[i] = NULL;
		if (other.m_inventory[i])
			m_inventory[i] = other.m_inventory[i] -> clone();
	}
}

// Delete anything I currently have, the other's destructor should handle the rest
Character& Character::operator= (const Character& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete m_inventory[i]; // delete on NULL does nothing anyway
			m_inventory[i] = NULL;
			if (other.m_inventory[i])
				m_inventory[i] = other.m_inventory[i] -> clone();
		}
		m_name = other.getName();
	}
	return (*this);
}
Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
		delete m_inventory[i];
	std::cout << getName() << " has died\n";
}