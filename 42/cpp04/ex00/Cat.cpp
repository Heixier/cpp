#include "Cat.hpp"

void Cat::makeSound(void) const
{
	std::cout << getType() << ": Meow\n";
}

Cat::Cat(void) : Animal()
{
	type = "Cat";
	std::cout << "A " << getType() << " has been created!\n";
}

Cat::Cat(const Cat& other) : Animal()
{
	type = other.getType();
	std::cout << "A "<< getType() << " Cat has been copied!\n";
}

Cat& Cat::operator= (const Cat& other)
{
	if (this != &other)
		Animal::operator=(other);
	std::cout << "A " << getType() << " has been copy assigned\n";
	return (*this);
}

Cat::~Cat(void) { std::cout << "A " << getType() << " has been destroyed!\n"; }