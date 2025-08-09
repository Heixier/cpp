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
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

Ice::Ice(void): AMateria("ice") { std::cout << "Ice has been created!\n"; }

Ice::Ice(const std::string& type): AMateria(type) { std::cout << getType() << " has been created!\n"; }

Ice::Ice(const Ice& other): AMateria(other) { }

Ice& Ice::operator= (const Ice& other)
{
	if (this != &other)
	{
		m_type = other.getType();
	}
	return (*this);
}

Ice::~Ice(void)
{
	std::cout << "Ice has been destroyed!\n";
}