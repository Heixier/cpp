#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAAnimal
{
	public:
		void makeSound(void) const;
		virtual const std::string& getType(void) const;

		WrongAAnimal(void);
		WrongAAnimal(const WrongAAnimal& other);
		WrongAAnimal& operator= (const WrongAAnimal& other);
		virtual ~WrongAAnimal(void);

	protected:
		std::string type;
};

#endif