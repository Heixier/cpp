#include "WrongAnimal.hpp"

void WrongAnimal::makeSound(void) const
{
	std::cout << getType() << ": ???\n";
}

const std::string& WrongAnimal::getType(void) const
{
	return (type);
}

WrongAnimal::WrongAnimal(void) : type("???") { std::cout << "An Animal of type " << type << " has been created!\n"; }
WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) { std::cout << "An animal of type " << type << " has been copied!\n"; }
WrongAnimal& WrongAnimal::operator= (const WrongAnimal& other)
{
	if (this != &other)
		type = other.type;
	std::cout << "An animal of type " << other.type << " has been copy assigned!\n";
	return (*this);
}
WrongAnimal::~WrongAnimal(void) { std::cout << "A WrongAnimal of type " << getType() << " has been destroyed!\n"; }