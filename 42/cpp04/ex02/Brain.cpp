#include "Brain.hpp"

void Brain::think(const std::string (&thoughts)[100])
{
	for (int i = 0; i < 100; i++)
		ideas[i] = thoughts[i];
}

void Brain::think(const std::string& thought)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = thought;
}

void Brain::think(const int idx, const std::string& thought)
{
	std::cout << "Now thinking about \"" << thought << "\" instead of \"" << ideas[idx] << "\"\n";
	ideas[idx] = thought;
}

const std::string& Brain::get_thought(int idx)
{
	return (ideas[idx]);
}

void Brain::think_aloud(int amount) const
{
	if (amount > 100)
		std::cout << "Not enough ideas!\n";
	for (int i = 0; i < amount; i++)
		std::cout << i << ": " << ideas[i] << '\n';
}

Brain::Brain(void)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = "* no thoughts head empty *";
	std::cout << "A Brain has been created!\n";
}

Brain::Brain(const Brain& other)
{
	think(other.ideas);
	std::cout << "A Brain has been copied!\n";
}

Brain& Brain::operator= (const Brain& other)
{
	if (this != &other)
		think(other.ideas);
	std::cout << "A Brain has been copy assigned!\n";
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "A Brain has been destroyed!\n";
}