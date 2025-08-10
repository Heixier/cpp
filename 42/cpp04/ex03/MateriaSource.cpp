#include "MateriaSource.hpp"
#include "colors.hpp"

void MateriaSource::list_materia(void) const
{
	std::cout << FF2 << "Current production: \n";
	for (int i = 0; i < 4; i++)
	{
		if (m_library[i])
			std::cout << GREY << i << ": " << m_library[i] -> get_color() << m_library[i] -> getType() << '\n' << END;
		else
			std::cout << GREY << i << ": < none >" << "\n" << END;
	}
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
	{
		std::cout << FF2 << "MateriaSource: " << RED << "Cannot generate nothing.\n" << END;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!m_library[i])
		{
			m_library[i] = m;
			std::cout << FF2 << "MateriaSource has started production of: " << m -> get_color() << m -> getType() << "!\n" << END;
			return;
		}
	}
	std::cout << FF2 << "MateriaSource: " << RED << "Production lines are too busy! Request has been rejected.\n" << END;
	delete m;
	m = NULL;
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (m_library[i] && m_library[i] -> getType() == type)
		{
			std::cout << FF2 << "Creating " << type << " from source...\n" << END;
			return (m_library[i] -> clone());
		}
	}
	std::cout << FF2 << "MateriaSource: " << RED << "Unknown type \"" << type << "\" cannot be synthesised.\n" << END;
	return (0); // WHY??? stupid pdf
}

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		m_library[i] = NULL; 
	std::cout << FF2 << "MateriaSource has been created!\n" << END;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
	{
		m_library[i] = NULL;
		if (other.m_library[i])
			m_library[i] = other.m_library[i] -> clone();
	}
	std::cout << FF2 << "MateriaSource has been copied!\n" << END;
}

MateriaSource& MateriaSource::operator= (const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete m_library[i];
			m_library[i] = NULL;
			if (other.m_library[i])
				m_library[i] = other.m_library[i] -> clone();
		}
		std::cout << FF2 << "MateriaSource has been copy assigned!\n" << END;
	}
	return *this;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		delete m_library[i];
		m_library[i] = NULL;
	}
	std::cout << FF2 << "MateriaSource has been destroyed!\n" << END;
}