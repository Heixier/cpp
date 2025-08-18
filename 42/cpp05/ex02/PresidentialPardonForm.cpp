#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > get_execute_grade())
		throw GradeTooLowException();
	std::cout << m_target << " has been pardoned by Zaphod Beeblebrox.\n";
}

PresidentialPardonForm::PresidentialPardonForm(): AForm(), m_target("the assassin who killed the author of this subject")
{
	std::cout << "die\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target): AForm("PresidentialPardonForm", 25, 5), m_target(target)
{
	std::cout << "Presidential Pardon Form has been created!\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other), m_target(other.m_target)
{
	std::cout << "Presidential Pardon Form has been copied!\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other); // exception should be thrown
		m_target = other.m_target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential Pardon Form has been destroyed!\n";
}
