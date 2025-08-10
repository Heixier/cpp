#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Colors.hpp"

int main(void)
{
	std::cout << ORANGE << " >> Deep copy test << \n";
	const Animal* i = new Cat();

	std::cout << "\nCat's first five thoughts: \n";
	static_cast<const Cat*>(i) -> think_aloud(5);

	std::cout << "\n[ Assigncat ]" << std::endl;
	Cat assigncat;
	assigncat = *static_cast<const Cat *>(i);
	assigncat.makeSound();
	std::cout << "\nAssigncat's first five thoughts: \n";
	assigncat.think_aloud(5);
	std::cout << "\nAdding new thought at index 1 and 3\n";
	assigncat.think_about(3, "Fish");
	assigncat.think_about(1, "Bird");
	std::cout << "\nAssigncat's first five thoughts now: \n";
	assigncat.think_aloud(5);

	std::cout << "\nCat's first five thoughts (to show that the original was not modified): \n";
	static_cast<const Cat*>(i) -> think_aloud(5);

	std::cout << "\n[ Copycat ]" << std::endl;
	Cat copycat(assigncat);
	copycat.makeSound();
	std::cout << "\nCopycat's first five thoughts: \n";
	copycat.think_aloud(5);

	std::cout << "\nAdding new thought at index 2\n";
	copycat.think_about(2, "Sleepy");

	std::cout << "\nCopycat's first five thoughts now: \n";
	copycat.think_aloud(5);

	std::cout << "\nAssigncat's first five thoughts (to show that original was not modified): \n";
	assigncat.think_aloud(5);

	std::cout << "\nDeep copy test end\n\n" << END;



	std::cout << BLUE << " >> Extra: Virtual function resolution test << \n";

	const Animal& indirect_dog = Dog();
	const Animal direct_dog = Dog(); // temporary Dog object for copy

	std::cout << "\nIndirect dog: \n";
	indirect_dog.makeSound();
	static_cast<const Dog&>(indirect_dog).think_aloud(5);

	std::cout << "Direct dog (will end up using Animal's makeSound()): \n";
	direct_dog.makeSound();

	std::cout << "\nExtra: Testing dog's get and set thought\n";
	Animal* modify_dog = new Dog();

	std::cout << "\nModifying Modifydog's idx 3 thought\n";
	static_cast<Dog *>(modify_dog) -> think_about(3, "Woof");

	std::cout << "\nModifydog's first five thoughts: \n";
	static_cast<Dog *>(modify_dog) -> think_aloud(5);

	std::cout << "\nModifydog's idx 3 thought: " 
	<< static_cast<Dog *>(modify_dog) -> get_thought(3)
	<< "\nModifydog's idx 1 thought: "
	<< static_cast<Dog *>(modify_dog) -> get_thought(1)
	<< '\n';



	std::cout << " >> Virtual function resolution test end << \n\n" << END;
	std::cout << GREEN << " >> Array test << \n";

	static const int animals = 10;
	const Animal*	zoo[animals];

	for (int i = 0; i < animals; i++)
	{
		if (i % 2)
			zoo[i] = new Cat();
		else
			zoo[i] = new Dog();
	}

	for (int i = 0; i < animals; i++)
	{
		std::cout << i << ": ";
		zoo[i] -> makeSound();
	}

	for (int i = animals - 1; i >= 0; i--) // delete in reverse order
		delete zoo[i];
	std::cout << "\n >> Array test end << \n" << END;

	std::cout << RED << "\n >> Final (illegal animal cloning) test\nCreating catdog from modify_dog: << \n\n";
	Animal* catdog = new Cat(*static_cast<Cat *>(modify_dog));

	static_cast<Cat *>(catdog) -> think_aloud(5);
	catdog -> makeSound();

	std::cout << "\n(yes that \"Dog\" just said \"Meow\". That's because the std::string type was copied over, \nbut it was constructed with Cat functions, so it uses the Cat's makeSound())\n";

	std::cout << "\n >> Illegal tests end << \n" << END << std::endl;

	std::cout << "Destroying...\n";
	delete catdog;
	delete modify_dog;
	delete i;
	return 0;
}