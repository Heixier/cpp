#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria* Cure::clone(void) const
{
	Cure* copy = new Cure(m_type);
	return (copy);
}

void Cure::use(ICharacter& target)
{
	std::cout << GREEN << "* heals " << target.getName() << "'s wounds *\n" << END;
}

Cure::Cure(void): AMateria("cure") { std::cout << GREEN << "cure has been created!\n" << END; }

Cure::Cure(const std::string& type): AMateria(type) { std::cout << GREEN << getType() << " has been created!\n" << END; }

Cure::Cure(const Cure& other): AMateria(other)
{
	std::cout << GREEN << other.getType() << " has been copied!\n" << END;
}

Cure& Cure::operator= (const Cure& other)
{
	if (this != &other)
		m_type = other.getType();
	std::cout << GREEN << other.getType() << " has been copy assigned!\n" << END;
	return (*this);
}

Cure::~Cure(void)
{
	std::cout << GREEN << getType() << " has been destroyed!\n" << END;
}