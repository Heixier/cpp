#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public AAnimal
{
	public:
		void makeSound(void) const;
		void show_thought(void) const;
		void think_aloud(int amount) const;
		void think_about(const std::string& thought);
		const std::string& getType(void) const;

		Brain* brain;

		Dog(void);
		Dog(const Dog& other);
		Dog& operator= (const Dog& other);
		virtual ~Dog(void);
};

#endif