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
		int get_price(void) const;

		Cure(const std::string& type);
		Cure(void);
		Cure(const Cure& other);
		Cure& operator= (const Cure& other);
		~Cure(void);
	
	private:
		const static int m_price = 750;
};

#endif