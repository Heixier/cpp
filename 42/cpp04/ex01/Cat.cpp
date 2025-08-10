#include "Cat.hpp"

const std::string Cat::m_sound = "Bark";

void Cat::makeSound(void) const
{
	std::cout << getType() << ": Meow\n";
}

void Cat::think_aloud(int amount) const
{
	brain -> think_aloud(amount);
}

void Cat::think_about(const std::string& thought)
{
	brain -> think(thought);
}

void Cat::think_about(const int idx, const std::string& thought)
{
	brain -> think(idx, thought);
}

const std::string& Cat::get_thought(const int idx) const
{
	return (brain -> get_thought(idx));
}

Cat::Cat(void) : Animal()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "A " << getType() << " has been created!\n";
}

Cat::Cat(const Cat& other) : Animal()
{
	type = other.getType();
	brain = new Brain(*static_cast<const Brain*>(other.brain));
	std::cout << "A " << getType() << " has been copied!\n";
}

Cat& Cat::operator= (const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		*brain = *(other.brain);
	}
	std::cout << "A " << getType() << " has been copy assigned\n";
	return (*this);
}

Cat::~Cat(void) { delete brain, std::cout << "A " << getType() << " has been destroyed!\n"; }