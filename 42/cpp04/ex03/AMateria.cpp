#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(void): m_type("???") { }
AMateria::AMateria(const std::string& type): m_type(type) { }
AMateria::AMateria(const AMateria& other): m_type(other.getType()) { std::cout << "AMateria copy constructor called\n"; }
AMateria& AMateria::operator= (const AMateria& other)
{
	if (this != &other)
		m_type = other.getType();
	return (*this);
}

const std::string& AMateria::getType(void) const { return m_type; }

void AMateria::use(ICharacter& target) { std::cout << "??? on " << target.getName() << "!\n"; }
AMateria::~AMateria(void) { std::cout << getType() << " has been destroyed!\n"; }