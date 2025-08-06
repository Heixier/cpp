#include "Cat.hpp"

void Cat::makeSound(void) const
{
	std::cout << getType() << ": Meow\n";
}

const std::string& Cat::getType(void) const
{
	return (type);
}

void Cat::show_thought(void) const
{
	std::cout << brain -> get_thought(0);
}

void Cat::think_aloud(int amount) const
{
	brain -> think_aloud(amount);
}

void Cat::think_about(const std::string& thought)
{
	std::cout << getType() << " has changed from thinking about " << brain -> get_thought(0) << " to " << thought << std::endl;
	brain -> think(thought);
}

Cat::Cat(void) : AAnimal()
{
	type = "Cat";
	brain = new Brain();
	brain -> think("sleepy");
	std::cout << "A " << getType() << " has been created!\n";
}

Cat::Cat(const Cat& other) : AAnimal()
{
	type = other.getType();
	brain = new Brain();
	*brain = *(other.brain);
	std::cout << "A " << getType() << " has been copied!\n";
}

Cat& Cat::operator= (const Cat& other)
{
	if (this != &other)
	{
		AAnimal::operator=(other);
		*brain = *(other.brain);
	}
	std::cout << "A " << getType() << " has been copy assigned\n";
	return (*this);
}

Cat::~Cat(void) { delete brain, std::cout << "A " << getType() << " has been destroyed!\n"; }