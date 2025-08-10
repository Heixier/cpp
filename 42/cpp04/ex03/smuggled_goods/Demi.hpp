#ifndef DEMI_HPP
#define DEMI_HPP

#include <iostream>

#include "../AMateria.hpp"
#include "../ICharacter.hpp"

class Demi: public AMateria
{
	public:
		AMateria* clone(void) const;
		void use (ICharacter& target);
		int get_price(void) const;

		Demi(const std::string& type);
		Demi(void);
		Demi(const Demi& other);
		Demi& operator= (const Demi& other);
		~Demi(void);
	
	private:
		const static int m_price = 8000;
};

#endif