#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() 
{
	learned_forms[0] = new ShrubberyCreationForm("NULL");
	learned_forms[1] = new RobotomyRequestForm("NULL");
	learned_forms[2] = new PresidentialPardonForm("NULL");
	std::cout << ORANGE << "Intern has been hired\n" << END;
}

Intern::Intern(const Intern& other)
{
	for (int i = 0; i < 3; i++)
		learned_forms[i] = other.learned_forms[i] -> clone("NULL");
	std::cout << ORANGE << "Intern has been copied!\n" << END;
}

Intern& Intern::operator= (const Intern& other)
{
	if (this != &other)
	{
		for (int i = 2; i >= 0; i--)
		{
			delete learned_forms[i];
			learned_forms[i] = NULL;		
		}
		for (int i = 0; i < 3; i++)
			learned_forms[i] = other.learned_forms[i] -> clone("NULL");
	}
	std::cout << ORANGE << "Intern has been copy assigned!\n" << END;
	return (*this);
}

Intern::~Intern()
{
	for (int i = 2; i >= 0; i--)
		delete learned_forms[i];
	std::cout << "Intern has been fired\n";
}

const char* Intern::InvalidFormException::what() const throw()
{
	return ("Requested form does not exist!\n");
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	const std::string types[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (int i = 0; i < 3; i++)
	{
		if (name == types[i])
		{
			std::cout << LIGHT_GREEN << "Intern creates:\n" << *learned_forms[i] << '\n' << END;
			return (learned_forms[i] -> clone(target));
		}
	}
	// throw InvalidFormException();
	std::cout << RED << "Intern doesn't know how to create form for \"" << name << "\"!\n";
	return (NULL);
}