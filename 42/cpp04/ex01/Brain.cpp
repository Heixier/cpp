#include "Brain.hpp"

void Brain::think(const std::string (&thoughts)[100])
{
	for (int i = 0; i < 100; i++)
		ideas[i] = thoughts[i];
}

void Brain::think(const std::string thought)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = thought;
}

const std::string& Brain::get_thought(int idx)
{
	return (ideas[idx]);
}

void Brain::think_aloud(void) const
{
	for (int i = 0; i < 100; i++)
		std::cout << ideas[i] << '\n';
}


Brain::Brain(void)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = "???";
	std::cout << "Brain has been created!\n";
}

Brain::Brain(const Brain& other) : thought(other.thought)
{
	think(other.ideas);
	std::cout << "Brain has been copied!\n";
}

Brain& Brain::operator= (const Brain& other)
{
	if (this != &other)
		think(other.ideas);
	std::cout << "Brain has been copy assigned!\n";
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain has been destroyed!\n";
}