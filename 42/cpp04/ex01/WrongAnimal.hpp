#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	public:
		void makeSound(void) const;
		virtual const std::string& getType(void) const;

		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator= (const WrongAnimal& other);
		virtual ~WrongAnimal(void);

	protected:
		std::string type;
};

#endif