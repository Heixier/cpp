#ifndef QUAKE_HPP
#define QUAKE_HPP

#include <iostream>

#include "../AMateria.hpp"
#include "../ICharacter.hpp"

class Quake: public AMateria
{
	public:
		AMateria* clone(void) const;
		void use (ICharacter& target);
		int get_price(void) const;

		Quake(const std::string& type);
		Quake(void);
		Quake(const Quake& other);
		Quake& operator= (const Quake& other);
		~Quake(void);
	
	private:
		const static int m_price = 1500;
};

#endif