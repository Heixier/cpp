#ifndef BOLT_HPP
#define BOLT_HPP

#include <iostream>

#include "../AMateria.hpp"
#include "../ICharacter.hpp"

class Bolt: public AMateria
{
	public:
		AMateria* clone(void) const;
		void use (ICharacter& target);
		int get_price(void) const;

		Bolt(const std::string& type);
		Bolt(void);
		Bolt(const Bolt& other);
		Bolt& operator= (const Bolt& other);
		~Bolt(void);
	
	private:
		const static int m_price = 600;
};

#endif