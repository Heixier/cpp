#include "Animal.hpp"

void Animal::makeSound(void) const
{
	std::cout << getType() << ": ???\n";
}

const std::string& Animal::getType(void) const
{
	return (type);
}

Animal::Animal(void) : type("???") { std::cout << "An Animal of type " << getType() << " has been created!\n"; }
Animal::Animal(const Animal& other) : type(other.type) { std::cout << "An Animal of type " << getType() << " has been copied!\n"; }
Animal& Animal::operator= (const Animal& other)
{
	std::cout << "An Animal of type " << other.getType() << " has been copy assigned!\n";
	if (this != &other)
		type = other.type;
	return (*this);
}
Animal::~Animal(void) { std::cout << "An Animal of type " << getType() << " has been destroyed!\n"; }