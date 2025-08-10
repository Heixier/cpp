#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

int Ice::get_price(void) const { return m_price; }

AMateria* Ice::clone(void) const
{
	Ice* copy = new Ice(m_type);
	return (copy);
}

void Ice::use(ICharacter& target)
{
	std::cout << get_color() << "* shoots an ice bolt at " << target.getName() << " *\n" << END;
}

Ice::Ice(void): AMateria("ice")
{
	m_color = ICE_BLUE;
	std::cout << get_color() << getType() << " has been created!\n" << END;
}

Ice::Ice(const std::string& type): AMateria(type)
{
	m_color = ICE_BLUE;
	std::cout << get_color() << getType() << " has been created!\n" << END;
}

Ice::Ice(const Ice& other): AMateria(other)
{
	m_color = ICE_BLUE;
	std::cout << get_color() << other.getType() << " has been copied!\n" << END;
}

Ice& Ice::operator= (const Ice& other)
{
	if (this != &other)
	{
		m_type = other.getType();
		m_color = other.get_color();
	}
	std::cout << get_color() << other.getType() << " has been copy assigned!\n" << END;
	return (*this);
}

Ice::~Ice(void)
{
	std::cout << get_color() << getType() << " has been destroyed!\n" << END;
}