#include "Character.hpp"

std::string const & Character::getName() const { return m_name; }

void Character::equip(AMateria *m)
{
	bool equipped = false;
	for (int i = 0; i < 4; i++)
	{
		if (!m_inventory[i])
		{
			m_inventory[i] = m;
			std::cout << "Equipped " << m -> getType() << " at slot " << i << "!\n";
			equipped = true;
		}
	}
	if (!equipped)
		std::cout << "Failed to equip " << m -> getType() << ". No slots left!\n";
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 4)
	{
		std::cout << idx << " is out of range!";
		return;
	}
	std::cout << "Unequipping " << m_inventory[idx] -> getType() << "!\n";
	m_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 4)
	{
		std::cout << idx << " is out of range!";
		return;
	}
	m_inventory[idx] -> use(target);
}

Character::Character(void): m_name("Bob") { }
Character::Character(const std::string& name): m_name(name) { }
Character::Character(const Character& other): m_name {other.getName()} { *this = other; }
Character& Character::operator= (const Character& other)
{
	AMateria* temp = NULL;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (other.m_inventory[i])
			{
				temp = other.m_inventory[i] -> clone();
				delete other.m_inventory[i];
				m_inventory[i] = temp;
			}
		}
		delete temp;
		m_name = other.getName();
	}
}
Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
		delete m_inventory[i];
	std::cout << getName() << " has died/\n";
}