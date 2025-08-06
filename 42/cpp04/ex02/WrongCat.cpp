#include "WrongCat.hpp"

void WrongCat::makeSound(void) const
{
	std::cout << "Meow\n";
}

WrongCat::WrongCat(void) : WrongAAnimal()
{
	type = "WrongCat";
	std::cout << "A " << getType() << " has been created!\n";
}
WrongCat::WrongCat(const WrongCat& other) : WrongAAnimal()
{
	type = other.getType();
	std::cout << "A " << getType() << " has been copied!\n";
}

WrongCat& WrongCat::operator= (const WrongCat& other)
{
	if (this != &other)
		WrongAAnimal::operator=(other);
	std::cout << "A " << getType() << " has been copy assigned\n";
	return (*this);
}

WrongCat::~WrongCat(void) { std::cout << "A " << getType() << " has been destroyed!\n"; }