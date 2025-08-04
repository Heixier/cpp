#include "Dog.hpp"

void Dog::makeSound(void) const
{
	std::cout << getType() << ": Bark\n";
}

Dog::Dog(void) : Animal()
{
	type = "Dog";
	std::cout << "An animal of type " << getType() << " has been created!\n";
}
Dog::Dog(const Dog& other) : Animal()
{
	type = other.getType();
	std::cout << "An animal of type " << getType() << " has been copied!\n";
}

Dog& Dog::operator= (const Dog& other)
{
	if (this != &other)
		Animal::operator=(other);
	std::cout << "An animal of " << getType() << " has been copy assigned\n";
	return (*this);
}

Dog::~Dog(void) { std::cout << "An Animal of type " << getType() << " has been destroyed!\n"; }