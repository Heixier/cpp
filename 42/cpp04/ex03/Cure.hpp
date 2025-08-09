#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure: public AMateria
{
	public:
		AMateria* clone(void) const;
		void use (ICharacter& target);

		Cure(const std::string& type);
		Cure(void);
		Cure(const Cure& other);
		Cure& operator= (const Cure& other);
		~Cure(void);
};

#endif