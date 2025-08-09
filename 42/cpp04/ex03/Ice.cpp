#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria* Ice::clone(void) const
{
	Ice* copy = new Ice(m_type);
	return (copy);
}

void Ice::use(ICharacter& target)
{
	std::cout << ICE_BLUE << "* shoots an ice bolt at " << target.getName() << " *\n" << END;
}

Ice::Ice(void): AMateria("ice") { std::cout << ICE_BLUE << "ice has been created!\n" << END; }

Ice::Ice(const std::string& type): AMateria(type) { std::cout << ICE_BLUE << getType() << " has been created!\n" << END; }

Ice::Ice(const Ice& other): AMateria(other)
{
	std::cout << ICE_BLUE << other.getType() << " has been copied!\n" << END;
}

Ice& Ice::operator= (const Ice& other)
{
	if (this != &other)
		m_type = other.getType();
	std::cout << ICE_BLUE << other.getType() << " has been copy assigned!\n" << END;
	return (*this);
}

Ice::~Ice(void)
{
	std::cout << ICE_BLUE << getType() << " has been destroyed!\n" << END;
}