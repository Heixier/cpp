#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal
{
	public:
		virtual void makeSound(void) const = 0;
		virtual const std::string& getType(void) const;
		virtual ~AAnimal(void);

	protected:
		std::string type;

		AAnimal(void);
		AAnimal(const AAnimal& other);
		AAnimal& operator= (const AAnimal& other);
};

#endif