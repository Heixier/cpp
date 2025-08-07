#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice: public AMateria
{
	public:
		AMateria* clone(void) const;
		void use (ICharacter& target);

		Ice(const std::string& type);
		Ice(void);
		Ice(const Ice& other);
		Ice& operator= (const Ice& other);
		~Ice(void);
};

#endif