#include "Character.hpp"
#include "colors.hpp"

void Character::check_inventory(void) const
{
	const static std::string keys = "qwer";

	std::cout << FF0 << getName() << "'s inventory:\n";
	for (int i = 0; i < 4; i++)
	{
		if (m_inventory[i])
			std::cout << GREY << keys[i] << ": " << m_inventory[i] -> get_color() << m_inventory[i] -> getType() << '\n' << END;
		else
			std::cout << GREY << keys[i] << ": <empty>\n" << END;
	}
}

void Character::check_sell_inventory(void) const
{
	std::cout << FF0 << getName() << "'s sell inventory:\n";
	for (int i = 0; i < 4; i++)
	{
		if (m_stock[i])
			std::cout << GREY << i << ": " << m_stock[i] -> get_color() << m_stock[i] -> getType() << YELLOW <<  " (" << m_stock[i] -> get_price() << ")\n" << END;
		else
			std::cout << GREY << i << ": <empty>\n" << END;
	}
}

void Character::sell(void)
{
	bool sold = false;
	for (int i = 0; i < 4; i++)
	{
		if (m_stock[i])
		{
			std::cout << "Sold " << m_stock[i] -> get_color() << m_stock[i] -> getType() << END << " for " << YELLOW << m_stock[i] -> get_price() << END << "!\n";
			sold = true;
		}
		delete m_stock[i];
		m_stock[i] = NULL;
	}
	if (sold)
		std::cout << YELLOW << "Sold all unequipped items!\n" << END;
}

std::string const & Character::getName() const { return m_name; }

void Character::equip(AMateria *m)
{
	sell();
	for (int i = 0; i < 4; i++)
	{
		if (!m_inventory[i])
		{
			if (!m)
			{
				std::cout << FF0 << getName() << GREY << ": Equipped literally nothing in slot " << i << "!\n" << END;
				return;
			}
			m_inventory[i] = m;
			std::cout << FF0 << getName() << ": Equipped " << m_inventory[i] -> getType() << " in slot " << i << "!\n" << END;
			return;
		}
	}
	if (m)
	{
		std::cout << FF0 << getName() << ": " << RED << "Failed to equip " << m -> getType() << ". No slots left! Materia has been lost...\n" << END;
		delete m;
		m = NULL;
	}
	else
		std::cout << FF0 << getName() << ": " << RED << "Failed to equip literally nothing (yes this still needs slots). No slots left!\n" << END;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << idx << " is out of range!";
		return;
	}
	if (!m_inventory[idx])
	{
		std::cout << FF0 << getName() << ": Nothing to unequip at slot " << idx << "!\n" << END;
		return;
	}
	std::cout << m_inventory[idx] -> get_color() << m_inventory[idx] -> getType() << " has been unequipped!\n" << END;
	for (int i = 0; i < 4; i++)
	{
		if (!m_stock[i])
		{
			m_stock[i] = m_inventory[idx];
			m_inventory[idx] = NULL;
			break;
		}
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << FF0 << getName() << ": " << RED << "Invalid inventory slot selected!\n" << END;
		return;
	}
	if (!m_inventory[idx])
	{
		std::cout << FF0 << getName() << ": " << GREY << "Nothing equipped at slot " << idx << "!\n" << END;
		return;
	}
	m_inventory[idx] -> use(target);
}

Character::Character(void): m_name("Cloud")
{
	std::cout << FF0 << getName() << " has been created!\n" << END;
	for (int i = 0; i < 4; i++)
	{
		m_inventory[i] = NULL;
		m_stock[i] = NULL;
	}
}

Character::Character(const std::string& name): m_name(name)
{
	for (int i = 0; i < 4; i++)
	{
		m_inventory[i] = NULL;
		m_stock[i] = NULL;
	}
	std::cout << FF0 << getName() << " has been created!\n" << END;
}

Character::Character(const Character& other): m_name(other.getName())
{
	for (int i =0; i < 4; i++)
	{
		m_inventory[i] = NULL;
		m_stock[i] = NULL;
		if (other.m_inventory[i])
			m_inventory[i] = other.m_inventory[i] -> clone();
		if (other.m_stock[i])
			m_stock[i] = other.m_stock[i] -> clone();
	}
	std::cout << FF0 << other.getName() << " has been copied!\n" << END;
}

// Delete anything I currently have, the other's destructor should handle the rest
Character& Character::operator= (const Character& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete m_inventory[i]; // delete on NULL does nothing anyway
			delete m_stock[i];

			m_inventory[i] = NULL;
			m_stock[i] = NULL;
			if (other.m_inventory[i])
				m_inventory[i] = other.m_inventory[i] -> clone();
			if (other.m_stock[i])
				m_stock[i] = other.m_stock[i] -> clone();
		}
		m_name = other.getName();
	}
	std::cout << FF0 << other.getName() << " has been copy assigned!\n";
	return (*this);
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		delete m_inventory[i];
		delete m_stock[i];
	}
	std::cout << FF0 << getName() << " has perished\n" << END;
}