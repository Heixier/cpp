#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAAnimal
{
	public:
		void makeSound(void) const;
		
		WrongCat(void);
		WrongCat(const WrongCat& other);
		WrongCat& operator= (const WrongCat& other);
		virtual ~WrongCat(void);
};

#endif