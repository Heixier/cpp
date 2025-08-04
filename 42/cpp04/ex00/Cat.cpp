#include "Cat.hpp"

void Cat::makeSound(void) const
{
	std::cout << "Hiss\n";
}

Cat::Cat(void) : Animal()
{
	type = "Cat";
	std::cout << "An animal of type " << type << " has been created!\n";
}
Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "An animal of type " << type << " has been copied!\n";
}

Cat& Cat::operator= (const Cat& other)
{
	std::cout << "An animal of " << type << " has been copy assigned\n";
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

Cat::~Cat(void) { std::cout << "An animal of " << type << " has been destroyed!\n"; }