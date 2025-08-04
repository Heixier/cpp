#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* i = new Cat();

	std::cout << "Assigncat: " << std::endl;
	Cat assigncat;
	assigncat = *static_cast<const Cat *>(i);
	assigncat.makeSound();

	std::cout << "Copycat: " << std::endl;
	const Cat copycat(*static_cast<const Cat*>(i));
	copycat.makeSound();

	copycat.think_aloud();

	const Animal doggy = Dog();

	doggy.makeSound();
	// make an array of cats and dogs or something 

	// cleanup
	delete i;
	return 0;
}
