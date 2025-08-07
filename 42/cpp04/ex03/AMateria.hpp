#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class ICharacter;

class AMateria
{
	public:
		AMateria(const std::string& type);
		const std::string& getType() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
		virtual ~AMateria(void);

	protected:
		std::string m_type;

		AMateria(void);
		AMateria(const AMateria& other);
		AMateria& operator= (const AMateria& other);
};

#endif