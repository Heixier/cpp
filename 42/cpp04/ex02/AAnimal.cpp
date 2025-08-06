#include "AAnimal.hpp"

void AAnimal::makeSound(void) const
{
	std::cout << getType() << ": ???\n";
}

const std::string& AAnimal::getType(void) const
{
	return (type);
}

AAnimal::AAnimal(void) : type("???") { std::cout << "An AAnimal has been created!\n"; }
AAnimal::AAnimal(const AAnimal& other) : type(other.type) { std::cout << "An AAnimal has been copied!\n"; }
AAnimal& AAnimal::operator= (const AAnimal& other)
{
	std::cout << "An AAnimal has been copy assigned!\n";
	if (this != &other)
		type = other.type;
	return (*this);
}
AAnimal::~AAnimal(void) { std::cout << "An AAnimal has been destroyed!\n"; }