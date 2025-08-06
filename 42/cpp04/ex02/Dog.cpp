#include "Dog.hpp"

void Dog::makeSound(void) const
{
	std::cout << getType() << ": Bark\n";
}

void Dog::show_thought(void) const
{
	std::cout << brain -> get_thought(0);
}

const std::string& Dog::getType(void) const
{
	return (type);
}

void Dog::think_aloud(int amount) const
{
	brain -> think_aloud(amount);
}

void Dog::think_about(const std::string& thought)
{
	brain -> think(thought);
}

Dog::Dog(void) : AAnimal()
{
	type = "Dog";
	brain = new Brain();
	brain -> think("walk!");
	std::cout << "A " << getType() << " has been created!\n";
}

Dog::Dog(const Dog& other) : AAnimal()
{
	type = other.getType();
	brain = new Brain();
	*brain = *(other.brain);
	std::cout << "A " << getType() << " has been copied!\n";
}

Dog& Dog::operator= (const Dog& other)
{
	if (this != &other)
	{
		AAnimal::operator=(other);
		*brain = *(other.brain);
	}
	std::cout << "A " << getType() << " has been copy assigned\n";
	return (*this);
}

Dog::~Dog(void) { delete brain, std::cout << "A " << getType() << " has been destroyed!\n"; }