#include "AMateria.hpp"
#include "ICharacter.hpp"

const std::string& AMateria::getType(void) const { return m_type; }
const std::string& AMateria::get_color(void) const { return m_color; }

AMateria::AMateria(void): m_type("???") { }
AMateria::AMateria(const std::string& type): m_type(type), m_color(GREY)
{
	std::cout << get_color() << "AMateria " << getType() << " has been created!\n" << END;
}

AMateria::AMateria(const AMateria& other): m_type(other.getType()), m_color(other.get_color())
{
	std::cout << get_color() << "AMateria " << other.getType() << " has been copied!\n" << END;
}

AMateria& AMateria::operator= (const AMateria& other)
{
	if (this != &other)
	{
		m_type = other.getType();
		m_color = other.get_color();
	}
	std::cout << get_color() << "AMateria " << other.getType() << " has been copy assigned!\n" << END;
	return (*this);
}

void AMateria::use(ICharacter& target) { std::cout << get_color() << "??? on " << target.getName() << "!\n"; }
AMateria::~AMateria(void) { std::cout << get_color() << "AMateria " << getType() << " has been destroyed!\n" << END; }