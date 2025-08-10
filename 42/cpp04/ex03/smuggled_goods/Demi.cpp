#include "Demi.hpp"
#include "../AMateria.hpp"
#include "../ICharacter.hpp"

int Demi::get_price(void) const { return m_price; }

AMateria* Demi::clone(void) const
{
	Demi* copy = new Demi(m_type);
	return (copy);
}

void Demi::use(ICharacter& target)
{
	std::cout << get_color() << "* crushes " << target.getName() << " with the force of gravity *\n" << END;
}

Demi::Demi(void): AMateria("demi")
{
	m_color = GREY;
	std::cout << get_color() << getType() << " has been created!\n" << END;
}

Demi::Demi(const std::string& type): AMateria(type)
{
	m_color = GREY;
	std::cout << get_color() << getType() << " has been created!\n" << END;
}

Demi::Demi(const Demi& other): AMateria(other)
{
	m_color = GREY;
	std::cout << get_color() << other.getType() << " has been copied!\n" << END;
}

Demi& Demi::operator= (const Demi& other)
{
	if (this != &other)
	{
		m_type = other.getType();
		m_color = other.get_color();
	}
	std::cout << get_color() << other.getType() << " has been copy assigned!\n" << END;
	return (*this);
}

Demi::~Demi(void)
{
	std::cout << get_color() << getType() << " has been destroyed!\n" << END;
}