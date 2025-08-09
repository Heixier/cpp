#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(void): m_type("???") { }
AMateria::AMateria(const std::string& type): m_type(type)
{
	std::cout << BROWN << "AMateria " << getType() << " has been created!\n" << END;
}

AMateria::AMateria(const AMateria& other): m_type(other.getType())
{
	std::cout << BROWN << "AMateria " << other.getType() << " has been copied!\n" << END;
}

AMateria& AMateria::operator= (const AMateria& other)
{
	if (this != &other)
		m_type = other.getType();
	std::cout << BROWN << "AMateria " << other.getType() << " has been copy assigned!\n" << END;
	return (*this);
}

const std::string& AMateria::getType(void) const { return m_type; }

void AMateria::use(ICharacter& target) { std::cout << "??? on " << target.getName() << "!\n"; }
AMateria::~AMateria(void) { std::cout << BROWN << "AMateria " << getType() << " has been destroyed!\n" << END; }