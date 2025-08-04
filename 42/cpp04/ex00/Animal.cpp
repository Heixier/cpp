#include "Animal.hpp"

void Animal::makeSound(void) const
{
	std::cout << type << " goes Vroom\n";
}

const std::string& Animal::getType(void) const
{
	return (type);
}

Animal::Animal(void) : type("Nissan Skyline") { std::cout << "An Animal of type " << type << " has been created!\n"; }
Animal::Animal(const Animal& other) : type(other.type) { std::cout << "An animal of type " << type << " has been copied!\n"; }
Animal& Animal::operator= (const Animal& other)
{
	std::cout << "An animal of type " << other.type << " has been copy assigned!\n";
	if (this != &other)
		type = other.type;
	return (*this);
}
Animal::~Animal(void) { std::cout << "An animal of type " << type << " has been destroyed!\n"; }