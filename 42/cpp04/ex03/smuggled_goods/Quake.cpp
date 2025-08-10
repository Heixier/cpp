#include "Quake.hpp"
#include "../AMateria.hpp"
#include "../ICharacter.hpp"

int Quake::get_price(void) const { return m_price; }

AMateria* Quake::clone(void) const
{
	Quake* copy = new Quake(m_type);
	return (copy);
}

void Quake::use(ICharacter& target)
{
	std::cout << get_color() << "* shakes the ground beneath " << target.getName() << " *\n" << END;
}

Quake::Quake(void): AMateria("quake")
{
	m_color = BROWN;
	std::cout << get_color() << getType() << " has been created!\n" << END;
}

Quake::Quake(const std::string& type): AMateria(type)
{
	m_color = BROWN;
	std::cout << get_color() << getType() << " has been created!\n" << END;
}

Quake::Quake(const Quake& other): AMateria(other)
{
	m_color = BROWN;
	std::cout << get_color() << other.getType() << " has been copied!\n" << END;
}

Quake& Quake::operator= (const Quake& other)
{
	if (this != &other)
	{
		m_type = other.getType();
		m_color = other.get_color();
	}
	std::cout << get_color() << other.getType() << " has been copy assigned!\n" << END;
	return (*this);
}

Quake::~Quake(void)
{
	std::cout << get_color() << getType() << " has been destroyed!\n" << END;
}