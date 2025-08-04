#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal
{
	public:
		void makeSound(void) const;
		void show_thought(void) const;
		void think_aloud(void) const;

		Brain* brain;

		Dog(void);
		Dog(const Dog& other);
		Dog& operator= (const Dog& other);
		virtual ~Dog(void);
};

#endif