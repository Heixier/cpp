#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice: public AMateria
{
	public:
		AMateria* clone(void) const;
		void use (ICharacter& target);
		int get_price(void) const;

		Ice(const std::string& type);
		Ice(void);
		Ice(const Ice& other);
		Ice& operator= (const Ice& other);
		~Ice(void);

	private:
		const static int m_price = 600;
};

#endif