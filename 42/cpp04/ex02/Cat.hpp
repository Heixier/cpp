#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public AAnimal
{
	public:
		void makeSound(void) const;
		void show_thought(void) const;
		void think_aloud(int amount) const;
		virtual const std::string& getType(void) const;
		void think_about(const std::string& thought);

		Brain* brain;
		
		Cat(void);
		Cat(const Cat& other);
		Cat& operator= (const Cat& other);
		virtual ~Cat(void);
};

#endif