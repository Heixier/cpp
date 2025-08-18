#include <iostream>

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "colors.hpp"

Intern::Intern() 
{
	std::cout << ORANGE << "Intern has been hired\n" << END;
}

AForm* Intern::create_shrubbery_form(const std::string& pdf_author) const
{
	return (new ShrubberyCreationForm(pdf_author));
}

AForm* Intern::create_robotomy_form(const std::string& is_an) const
{
	return (new RobotomyRequestForm(is_an));
}

AForm* Intern::create_presidential_form(const std::string& idiot) const
{
	return (new PresidentialPardonForm(idiot));
}

Intern::Intern(const Intern& other)
{
	(void)other;
	std::cout << ORANGE << "Intern has been copied\n" << END;
}

Intern& Intern::operator= (const Intern& other)
{
	(void)other;
	std::cout << ORANGE << "Intern has been copy assigned!\n" << END;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern has been fired\n";
}

const char* Intern::InvalidFormException::what() const throw()
{
	return ("Requested form does not exist!");
}

AForm* Intern::makeForm(const std::string& name, const std::string& target) const
{
	const std::string types[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	static AForm* (Intern::*compliance[3])(const std::string&) const = 
	{
		&Intern::create_shrubbery_form,
		&Intern::create_robotomy_form,
		&Intern::create_presidential_form
	};

	AForm *tmp = NULL;
	for (int i = 0; i < 3; i++)
	{
		if (name == types[i])
		{
			tmp = (this->*compliance[i])(target);
			std::cout << LIGHT_GREEN << "Intern creates:\n" << *tmp << '\n' << END;
			return (tmp);
		}
	}
	throw InvalidFormException();
	// std::cout << RED << "Intern doesn't know how to create form for \"" << name << "\"!\n";
	// return (NULL);
}