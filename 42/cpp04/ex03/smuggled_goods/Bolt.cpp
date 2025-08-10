#include "Bolt.hpp"
#include "../AMateria.hpp"
#include "../ICharacter.hpp"

int Bolt::get_price(void) const { return m_price; }

AMateria* Bolt::clone(void) const
{
	Bolt* copy = new Bolt(m_type);
	return (copy);
}

void Bolt::use(ICharacter& target)
{
	std::cout << get_color() << "* strikes " << target.getName() << " with a bolt of electricity *\n" << END;
}

Bolt::Bolt(void): AMateria("bolt")
{
	m_color = YELLOW;
	std::cout << get_color() << getType() << " has been created!\n" << END;
}

Bolt::Bolt(const std::string& type): AMateria(type)
{
	m_color = YELLOW;
	std::cout << get_color() << getType() << " has been created!\n" << END;
}

Bolt::Bolt(const Bolt& other): AMateria(other)
{
	m_color = YELLOW;
	std::cout << get_color() << other.getType() << " has been copied!\n" << END;
}

Bolt& Bolt::operator= (const Bolt& other)
{
	if (this != &other)
	{
		m_type = other.getType();
		m_color = other.get_color();
	}
	std::cout << get_color() << other.getType() << " has been copy assigned!\n" << END;
	return (*this);
}

Bolt::~Bolt(void)
{
	std::cout << get_color() << getType() << " has been destroyed!\n" << END;
}