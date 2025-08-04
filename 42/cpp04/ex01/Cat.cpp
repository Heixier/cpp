#include "Cat.hpp"

void Cat::makeSound(void) const
{
	std::cout << getType() << ": Meow\n";
}

void Cat::show_thought(void) const
{
	std::cout << brain -> get_thought(0);
}

void Cat::think_aloud(void) const
{
	brain -> think_aloud();
}

Cat::Cat(void) : Animal()
{
	type = "Cat";
	brain = new Brain();
	brain -> think("sleepy");
	std::cout << "An animal of type " << getType() << " has been created!\n";
}

Cat::Cat(const Cat& other) : Animal()
{
	type = other.getType();
	brain = new Brain();
	*brain = *(other.brain);
	std::cout << "An animal of type " << getType() << " has been copied!\n";
}

Cat& Cat::operator= (const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		*brain = *(other.brain);
	}
	std::cout << "An animal of type " << getType() << " has been copy assigned\n";
	return (*this);
}

Cat::~Cat(void) { delete brain, std::cout << "An Animal of type " << getType() << " has been destroyed!\n"; }