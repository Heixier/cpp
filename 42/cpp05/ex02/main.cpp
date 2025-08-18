// #include <iostream>
#include <unistd.h>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	// AForm original; // abstract class will not compile

	Bureaucrat alex("Frank", 141);
	Bureaucrat max("Jim", 3);

	AForm* form = new ShrubberyCreationForm("France");
	alex.executeForm(*form);

	alex.signForm(*form);
	max.signForm(*form);

	AForm* copy = new ShrubberyCreationForm(*static_cast<ShrubberyCreationForm *>(form));
	// try
	// {
	// 	*static_cast<ShrubberyCreationForm *>(form) = *static_cast<ShrubberyCreationForm *>(copy);
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cerr << RED << e.what() << "\n\n" << END;
	// }

	alex.executeForm(*copy);
	max.executeForm(*copy);

	delete copy;
	delete form;

	form = new RobotomyRequestForm("Zoe");
	alex.executeForm(*form);

	alex.signForm(*form);
	max.signForm(*form);

	copy = new RobotomyRequestForm(*static_cast<RobotomyRequestForm *>(form));
	// try
	// {
	// 	*static_cast<RobotomyRequestForm *>(form) = *static_cast<RobotomyRequestForm *>(copy);
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cerr << RED << e.what() << "\n\n" << END;
	// }

	alex.executeForm(*copy);
	max.executeForm(*copy);

	delete copy;
	delete form;

	form = new PresidentialPardonForm("Adam");
	alex.executeForm(*form);

	alex.signForm(*form);
	max.signForm(*form);

	copy = new PresidentialPardonForm(*static_cast<PresidentialPardonForm *>(form));
	// try
	// {
	// 	*static_cast<PresidentialPardonForm *>(form) = *static_cast<PresidentialPardonForm *>(copy);
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cerr << RED << e.what() << "\n\n" << END;
	// }

	alex.executeForm(*copy);
	max.executeForm(*copy);

	delete copy;
	delete form;
}