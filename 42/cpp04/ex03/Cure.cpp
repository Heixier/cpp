#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

int Cure::get_price(void) const { return m_price; }

AMateria* Cure::clone(void) const
{
	Cure* copy = new Cure(m_type);
	return (copy);
}

void Cure::use(ICharacter& target)
{
	std::cout << get_color() << "* heals " << target.getName() << "'s wounds *\n" << END;
}

Cure::Cure(void): AMateria("cure")
{
	m_color = GREEN;
	std::cout << get_color() << "Cure has been created!\n" << END;
}

Cure::Cure(const std::string& type): AMateria(type)
{
	m_color = GREEN;
	std::cout << get_color() << getType() << " has been created!\n" << END;
}

Cure::Cure(const Cure& other): AMateria(other)
{
	m_color = GREEN;
	std::cout << get_color() << other.getType() << " has been copied!\n" << END;
}

Cure& Cure::operator= (const Cure& other)
{
	if (this != &other)
	{
		m_type = other.getType();
		m_color = other.get_color();
	}
	std::cout << get_color() << other.getType() << " has been copy assigned!\n" << END;
	return (*this);
}

Cure::~Cure(void)
{
	std::cout << get_color() << getType() << " has been destroyed!\n" << END;
}