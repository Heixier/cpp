#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() 
{
	// learned_forms[0] = new ShrubberyCreationForm("NULL");
	// learned_forms[1] = new RobotomyRequestForm("NULL");
	// learned_forms[2] = new PresidentialPardonForm("NULL");
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
	// for (int i = 0; i < 3; i++)
	// 	learned_forms[i] = other.learned_forms[i] -> clone("NULL");
	AForm* why_do_I_need_a_copy_constructor = other.makeForm("ignore this it's just a useless copy constructor because of forced ocf and -Werror", "ugh");
	delete why_do_I_need_a_copy_constructor; // even though it is NULL
	std::cout << ORANGE << "Intern has been copied (but what's the point?)\n" << END;
}

Intern& Intern::operator= (const Intern& other)
{
	if (this != &other)
	{
		// for (int i = 2; i >= 0; i--)
		// {
		// 	delete learned_forms[i];
		// 	learned_forms[i] = NULL;		
		// }
		// for (int i = 0; i < 3; i++)
		// 	learned_forms[i] = other.learned_forms[i] -> clone("NULL");
	}
	std::cout << ORANGE << "Intern has been copy assigned!\n" << END;
	return (*this);
}

Intern::~Intern()
{
	// for (int i = 2; i >= 0; i--)
	// 	delete learned_forms[i];
	std::cout << "Intern has been fired\n";
}

// const char* Intern::InvalidFormException::what() const throw()
// {
// 	return ("Requested form does not exist!\n");
// }

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
			// std::cout << LIGHT_GREEN << "Intern creates:\n" << *learned_forms[i] << '\n' << END;
			// return (learned_forms[i] -> clone(target));
			return (tmp);
		}
	}
	// throw InvalidFormException();
	std::cout << RED << "Intern doesn't know how to create form for \"" << name << "\"!\n";
	return (NULL);
}