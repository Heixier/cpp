#include "Dog.hpp"

void Dog::makeSound(void) const
{
	std::cout << getType() << ": Bark\n";
}

void Dog::show_thought(void) const
{
	std::cout << brain -> get_thought(0);
}

void Dog::think_aloud(void) const
{
	brain -> think_aloud();
}

Dog::Dog(void) : Animal()
{
	type = "Dog";
	brain = new Brain();
	brain -> think("walk!");
	std::cout << "An animal of type " << getType() << " has been created!\n";
}

Dog::Dog(const Dog& other) : Animal()
{
	type = other.getType();
	brain = new Brain();
	*brain = *(other.brain);
	std::cout << "An animal of type " << getType() << " has been copied!\n";
}

Dog& Dog::operator= (const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		*brain = *(other.brain);
	}
	std::cout << "An animal of " << getType() << " has been copy assigned\n";
	return (*this);
}

Dog::~Dog(void) { delete brain, std::cout << "An Animal of type " << getType() << " has been destroyed!\n"; }