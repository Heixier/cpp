#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << "Assigncat: " << std::endl;
	Cat assigncat;
	assigncat = *static_cast<const Cat *>(i);
	assigncat.makeSound();

	std::cout << "Copycat: " << std::endl;
	const Cat copycat(*static_cast<const Cat*>(i));
	copycat.makeSound();

	std::cout << "Wrongcat: " << std::endl;
	const WrongAnimal* wrongcat = new WrongCat();
	std::cout << wrongcat->getType() << " " << std::endl;
	wrongcat->makeSound();

	// cleanup
	delete meta;
	delete j;
	delete i;
	delete wrongcat;
	return 0;
	
}
