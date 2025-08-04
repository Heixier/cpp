#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
		virtual void makeSound(void) const;
		virtual const std::string& getType(void) const;

		Animal(void);
		Animal(const Animal& other);
		Animal& operator= (const Animal& other);
		virtual ~Animal(void);

	protected:
		std::string type;
};

#endif