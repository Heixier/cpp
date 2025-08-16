#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include <cstdlib>

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > get_execute_grade())
		throw GradeTooLowException();
	std::cout << " * drill sounds * \n";
	srand(time(NULL));
	if (rand() % 2)
		std::cout << GREEN << m_target << " has been successfully robotomized!\n" << END;
	else
		std::cout << ORANGE << "Robotomy has failed\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("RobotomyRequestForm", 72, 45), m_target(target)
{
	std::cout << "Robotomy Request Form has been created!\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other), m_target(other.m_target)
{
	std::cout << "Robotomy Request Form has been copied!\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other); // exception should be thrown
		m_target = other.m_target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy Request Form has been destroyed!\n";
}
