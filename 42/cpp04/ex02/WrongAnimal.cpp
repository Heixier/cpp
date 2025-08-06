#include "WrongAnimal.hpp"

void WrongAAnimal::makeSound(void) const
{
	std::cout << getType() << ": ???\n";
}

const std::string& WrongAAnimal::getType(void) const
{
	return (type);
}

WrongAAnimal::WrongAAnimal(void) : type("???") { std::cout << "An AAnimal of type " << type << " has been created!\n"; }
WrongAAnimal::WrongAAnimal(const WrongAAnimal& other) : type(other.type) { std::cout << "An animal of type " << type << " has been copied!\n"; }
WrongAAnimal& WrongAAnimal::operator= (const WrongAAnimal& other)
{
	if (this != &other)
		type = other.type;
	std::cout << "An animal of type " << other.type << " has been copy assigned!\n";
	return (*this);
}
WrongAAnimal::~WrongAAnimal(void) { std::cout << "A WrongAAnimal of type " << getType() << " has been destroyed!\n"; }