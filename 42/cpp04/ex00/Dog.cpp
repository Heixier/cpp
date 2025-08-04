#include "Dog.hpp"

void Dog::makeSound(void) const
{
	std::cout << "Pant\n";
}

Dog::Dog(void) : Animal()
{
	type = "Dog";
	std::cout << "An animal of type " << type << " has been created!\n";
}
Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "An animal of type " << type << " has been copied!\n";
}

Dog& Dog::operator= (const Dog& other)
{
	std::cout << "An animal of " << type << " has been copy assigned\n";
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

Dog::~Dog(void) { std::cout << "An animal of " << type << " has been destroyed!\n"; }