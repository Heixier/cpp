#include "Fire.hpp"
#include "../AMateria.hpp"
#include "../ICharacter.hpp"

int Fire::get_price(void) const { return m_price; }

AMateria* Fire::clone(void) const
{
	Fire* copy = new Fire(m_type);
	return (copy);
}

void Fire::use(ICharacter& target)
{
	std::cout << get_color() << "* blasts fire at " << target.getName() << " *\n" << END;
}

Fire::Fire(void): AMateria("fire")
{
	m_color = ORANGE;
	std::cout << get_color() << getType() << " has been created!\n" << END;
}

Fire::Fire(const std::string& type): AMateria(type)
{
	m_color = ORANGE;
	std::cout << get_color() << getType() << " has been created!\n" << END;
}

Fire::Fire(const Fire& other): AMateria(other)
{
	m_color = ORANGE;
	std::cout << get_color() << other.getType() << " has been copied!\n" << END;
}

Fire& Fire::operator= (const Fire& other)
{
	if (this != &other)
	{
		m_type = other.getType();
		m_color = other.get_color();
	}
	std::cout << get_color() << other.getType() << " has been copy assigned!\n" << END;
	return (*this);
}

Fire::~Fire(void)
{
	std::cout << get_color() << getType() << " has been destroyed!\n" << END;
}