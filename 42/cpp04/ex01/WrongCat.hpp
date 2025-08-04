#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal
{
	public:
		void makeSound(void) const;
		
		WrongCat(void);
		WrongCat(const WrongCat& other);
		WrongCat& operator= (const WrongCat& other);
		virtual ~WrongCat(void);
};

#endif