#ifndef FIRE_HPP
#define FIRE_HPP

#include <iostream>

#include "../AMateria.hpp"
#include "../ICharacter.hpp"

class Fire: public AMateria
{
	public:
		AMateria* clone(void) const;
		void use (ICharacter& target);
		int get_price(void) const;

		Fire(const std::string& type);
		Fire(void);
		Fire(const Fire& other);
		Fire& operator= (const Fire& other);
		~Fire(void);
	
	private:
		const static int m_price = 600;
};

#endif