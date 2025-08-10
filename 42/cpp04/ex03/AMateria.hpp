#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "colors.hpp"

class ICharacter;

class AMateria
{
	public:
		AMateria(const std::string& type);
		const std::string& getType() const;
		const std::string& get_color(void) const;
		virtual int get_price(void) const = 0;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
		virtual ~AMateria(void);

	protected:
		std::string m_type;
		std::string m_color;

		AMateria(void);
		AMateria(const AMateria& other);
		AMateria& operator= (const AMateria& other);
};

#endif