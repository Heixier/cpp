#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal
{
	public:
		void makeSound(void) const;
		
		Cat(void);
		Cat(const Cat& other);
		Cat& operator= (const Cat& other);
		virtual ~Cat(void);
};

#endif