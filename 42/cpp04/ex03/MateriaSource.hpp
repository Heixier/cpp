#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource: public IMateriaSource
{
	public:
		void list_materia(void) const;
		void learnMateria(AMateria* m);
		AMateria* createMateria(const std::string& type);

		MateriaSource(void);
		MateriaSource(const MateriaSource& other);
		MateriaSource& operator= (const MateriaSource& other);
		~MateriaSource(void);
	
	private:
		AMateria* m_library[4];
};

#endif