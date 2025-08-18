#include "Bureaucrat.hpp"
#include "Form.hpp"

#include "colors.hpp"

static void check_grade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::increment()
{
	if (m_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	m_grade--;
}

void Bureaucrat::decrement()
{
	if (m_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	m_grade++;
}

const std::string& Bureaucrat::getName() const
{
	return (m_name);
}

int Bureaucrat::getGrade() const
{
	return (m_grade);
}

bool Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << LIGHT_GREEN << *this << " signed " << form << '\n' << END;
		return (true);
	}
	catch (const std::exception &e)
	{
		std::cout << RED << *this << " couldn't sign\n" << form << " because:\n" << e.what() << '\n' << END;
		return (false);
	}
}


Bureaucrat::Bureaucrat(): m_name("Snoopy"), m_grade(150)
{
	check_grade(m_grade);
	std::cout << "Bureaucrat constructed\nName: " << m_name << "\nGrade: " << m_grade << '\n';
}

Bureaucrat::Bureaucrat(int grade): m_name("Snoopy"), m_grade(grade)
{
	check_grade(m_grade);
	std::cout << "Bureaucrat constructed\nName: " << m_name << "\nGrade: " << m_grade << '\n';
}

Bureaucrat::Bureaucrat(const std::string& name): m_name(name), m_grade(150)
{
	check_grade(m_grade);
	std::cout << "Bureaucrat constructed\nName: " << m_name << "\nGrade: " << m_grade << '\n';
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): m_name(name), m_grade(grade)
{
	check_grade(m_grade);
	std::cout << "Bureaucrat constructed\nName: " << m_name << "\nGrade: " << m_grade << '\n';
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): m_name(other.m_name), m_grade(other.m_grade)
{
	std::cout << "Bureaucrat " << m_name << " was copied\n";
}

Bureaucrat& Bureaucrat::operator= (const Bureaucrat& other)
{
	throw CannotBeModifiedException();
	if (this != &other)
	{
		// copying just grade is confusing behaviour because users will righfully assume the whole thing was copied
		// this can cause weird bugs later on when the name is checked
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "Bureaucrat " << m_name << ", grade: " << m_grade << " was fired\n" << END;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Exception: grade too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Exception: grade too low!");
}

const char* Bureaucrat::CannotBeModifiedException::what() const throw()
{
	return ("Exception: object has unmodifiable attributes!");
}

std::ostream& operator<< (std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", " << bureaucrat.getGrade() << '.';
	return (os);
}