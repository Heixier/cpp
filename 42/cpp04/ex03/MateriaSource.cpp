#include "MateriaSource.hpp"

void MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
	{
		std::cout << "MateriaSource: Your lack of knowledge has been rejected.\n";
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!m_library[i])
		{
			m_library[i] = m;
			std::cout << "MateriaSource has learned: " << m -> getType() << "!\n";
			return;
		}
	}
	std::cout << "MateriaSource cannot learn anything else! Knowledge has been destroyed...\n";
	delete m;
	m = NULL;
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (m_library[i] && m_library[i] -> getType() == type)
		{
			std::cout << "Type " << type << " has been created from source!\n";
			return (m_library[i] -> clone());
		}
	}
	std::cout << "MateriaSource has no knowledge of type " << type << " ...\n";
	return (0); // WHY??? stupid pdf
}

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		m_library[i] = NULL; 
	std::cout << "MateriaSource has been created!\n";
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
	{
		m_library[i] = NULL;
		if (other.m_library[i])
			m_library[i] = other.m_library[i] -> clone();
	}
	std::cout << "MateriaSource has been copied!\n";
}

MateriaSource& MateriaSource::operator= (const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
	{
		delete m_library[i];
		m_library[i] = NULL;
		if (other.m_library[i])
			m_library[i] = other.m_library[i] -> clone();
	}
	std::cout << "MateriaSource has been copy assigned!\n";
	return *this;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		delete m_library[i];
		m_library[i] = NULL;
	}
	std::cout << "MateriaSource has been destroyed!\n";
}