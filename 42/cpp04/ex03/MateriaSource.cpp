#include "MateriaSource.hpp"
#include "colors.hpp"

// void MateriaSource::list_materia(void) const
// {
// 	for (int i = 0; i < 4; i++)
// 	{
// 		if (m_library[i])
// 			std::cout << PURPLE << "MateriaSource: " << m_library[i] -> getType() << " is equipped in slot " << i << END;
// 		else
// 			std::cout << PURPLE << "MateriaSource: " << "nothing is equipped in slot " << i << END;
// 	}
// }

void MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
	{
		std::cout << PURPLE << "MateriaSource: " << RED << "Your lack of knowledge has been rejected.\n" << END;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!m_library[i])
		{
			m_library[i] = m;
			std::cout << PURPLE << "MateriaSource has learned: " << m -> getType() << "!\n" << END;
			return;
		}
	}
	std::cout << PURPLE << "MateriaSource: " << RED << "Library is full! Knowledge has been destroyed...\n" << END;
	delete m;
	m = NULL;
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (m_library[i] && m_library[i] -> getType() == type)
		{
			std::cout << PURPLE << "Creating " << type << " from source...\n" << END;
			return (m_library[i] -> clone());
		}
	}
	std::cout << PURPLE << "MateriaSource: " << RED << "Unknown knowledge of type \"" << type << "\" cannot be created.\n" << END;
	return (0); // WHY??? stupid pdf
}

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		m_library[i] = NULL; 
	std::cout << PURPLE << "MateriaSource has been created!\n" << END;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
	{
		m_library[i] = NULL;
		if (other.m_library[i])
			m_library[i] = other.m_library[i] -> clone();
	}
	std::cout << PURPLE << "MateriaSource has been copied!\n" << END;
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
		std::cout << PURPLE << "MateriaSource has been copy assigned!\n" << END;
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
	std::cout << PURPLE << "MateriaSource has been destroyed!\n" << END;
}