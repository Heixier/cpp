#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal
{
	public:
		void makeSound(void) const;
		
		Dog(void);
		Dog(const Dog& other);
		Dog& operator= (const Dog& other);
		virtual ~Dog(void);
};

#endif