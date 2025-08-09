#include "Character.hpp"
#include "colors.hpp"

// void Character::check_inventory(void) const
// {
// 	for (int i = 0; i < 4; i++)
// 	{
// 		if (m_inventory[i])
// 			std::cout << PEACH << getName() << ": " << m_inventory[i] -> getType() << " is equipped in slot " << i << END;
// 		else
// 			std::cout << PEACH << getName() << ": nothing is equipped in slot " << i << END;
// 	}
// }

std::string const & Character::getName() const { return m_name; }

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!m_inventory[i])
		{
			if (!m)
			{
				std::cout << PEACH << getName() << GREY << ": Equipped literally nothing at slot " << i << "!\n" << END;
				return;
			}
			m_inventory[i] = m;
			std::cout << PEACH << getName() << ": Equipped " << m_inventory[i] -> getType() << " at slot " << i << "!\n" << END;
			return;
		}
	}
	if (m)
	{
		std::cout << PEACH << getName() << ": " << RED << "Failed to equip " << m -> getType() << ". No slots left! Materia has been lost...\n" << END;
		delete m;
		m = NULL;
	}
	else
		std::cout << PEACH << getName() << ": " << RED << "Failed to equip literally nothing (yes this still needs slots). No slots left!\n" << END;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << idx << " is out of range!";
		return;
	}
	std::cout << PEACH << getName() << ": Unequipping " << m_inventory[idx] -> getType() << "!\n <<" << END;
	m_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << PEACH << getName() << ": " << RED << idx << " is out of range (0-3)!\n" << END;
		return;
	}
	if (!m_inventory[idx])
	{
		std::cout << PEACH << getName() << ": " << GREY << "Nothing equipped at " << idx << "!\n" << END;
		return;
	}
	m_inventory[idx] -> use(target);
}

Character::Character(void): m_name("Bob")
{
	std::cout << PEACH << getName() << " has been created!\n" << END;
	for (int i = 0; i < 4; i++)
		m_inventory[i] = NULL;
}

Character::Character(const std::string& name): m_name(name)
{
	for (int i = 0; i < 4; i++)
		m_inventory[i] = NULL;
	std::cout << PEACH << getName() << " has been created!\n" << END;
}

Character::Character(const Character& other): m_name(other.getName())
{
	for (int i =0; i < 4; i++)
	{
		m_inventory[i] = NULL;
		if (other.m_inventory[i])
			m_inventory[i] = other.m_inventory[i] -> clone();
	}
	std::cout << PEACH << other.getName() << " has been copied!\n" << END;
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
	std::cout << PEACH << other.getName() << " has been copy assigned!\n";
	return (*this);
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
		delete m_inventory[i];
	std::cout << PEACH << getName() << " has died\n" << END;
}