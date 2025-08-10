#include "Dog.hpp"

const std::string Dog::m_sound = "Bark";

void Dog::makeSound(void) const
{
	std::cout << getType() << ": " << m_sound << '\n';
}

void Dog::think_aloud(int amount) const
{
	brain -> think_aloud(amount);
}

void Dog::think_about(const std::string& thought)
{
	brain -> think(thought);
}

void Dog::think_about(const int idx, const std::string& thought)
{
	brain -> think(idx, thought);
}

const std::string& Dog::get_thought(const int idx) const
{
	return(brain -> get_thought(idx));
}

Dog::Dog(void) : AAnimal()
{
	type = "Dog";
	brain = new Brain();
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