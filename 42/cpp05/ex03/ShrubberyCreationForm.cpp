#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <fstream>

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > get_execute_grade())
		throw GradeTooLowException();
	std::ofstream shrubbery;
	shrubbery.open((m_target + "_shrubbery").c_str());
	shrubbery << "$> tree\n\
.\n\
├── AForm.cpp\n\
├── AForm.hpp\n\
├── Bureaucrat.cpp\n\
├── Bureaucrat.hpp\n\
├── colors.hpp\n\
├── France_shrubbery\n\
├── Intern.cpp\n\
├── Intern.hpp\n\
├── main.cpp\n\
├── Makefile\n\
├── PresidentialPardonForm.cpp\n\
├── PresidentialPardonForm.hpp\n\
├── RobotomyRequestForm.cpp\n\
├── RobotomyRequestForm.hpp\n\
├── ShrubberyCreationForm.cpp\n\
└── ShrubberyCreationForm.hpp\n\
\n\
1 directory, 16 files\n";
	shrubbery.close();
}

AForm* ShrubberyCreationForm::clone(const std::string &target) const
{
	AForm* copy = new ShrubberyCreationForm(target);
	return (copy);
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("ShrubberyCreationForm", 145, 137), m_target(target)
{
	std::cout << "Shrubbery Creation Form has been created!\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other), m_target(other.m_target)
{
	std::cout << "Shrubbery Creation Form has been copied!\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other); // exception should be thrown
		m_target = other.m_target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery Creation Form has been destroyed!\n";
}
