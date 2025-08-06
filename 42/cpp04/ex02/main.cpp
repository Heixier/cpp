#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Colors.hpp"

int main(void)
{
	std::cout << ORANGE << "Deep copy test start\n";
	const AAnimal* i = new Cat();

	static_cast<const Cat*>(i) -> think_aloud(10);
	std::cout << "\nAssigncat: " << std::endl;
	Cat assigncat;
	assigncat = *static_cast<const Cat *>(i);
	assigncat.makeSound();
	assigncat.think_aloud(10);

	assigncat.think_about("hungry"); // Change thought to demonstrate deep copy
	std::cout << "\nCopycat: " << std::endl;
	const Cat copycat(assigncat);
	copycat.makeSound();
	copycat.think_aloud(10);

	std::cout << "Deep copy test end\n\n" << END;
	std::cout << GREEN << "Array test start\n";

	const AAnimal*	zoo[2];
	zoo[0] = new Cat();
	zoo[1] = new Dog();

	for (int i = 0; i < 2; i++)
		zoo[i]->makeSound();

	for (int i = 0; i < 2; i++)
		delete zoo[i];
	std::cout << "Array test end\n\n" << END;
	delete i;

	// AAnimal direct_not_ok = Dog();
	// direct_not_ok.makeSound();
	const AAnimal& indirect_ok = Cat();
	indirect_ok.makeSound();

	return 0;
}