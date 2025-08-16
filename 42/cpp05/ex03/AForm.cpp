#include "AForm.hpp"
#include "Bureaucrat.hpp"

static void check_grade(int grade)
{
	if (grade > 150)
		throw AForm::GradeTooLowException();
	if (grade < 1)
		throw AForm::GradeTooHighException();
}

const std::string& AForm::get_name() const
{
	return (m_name);
}

bool AForm::is_signed() const
{
	return (m_signed);
}

int AForm::get_sign_grade() const
{
	return (m_sign_grade);
}

int AForm::get_execute_grade() const
{
	return (m_execute_grade);
}

void AForm::beSigned(const Bureaucrat& signee)
{
	if (signee.getGrade() <= m_sign_grade)
		m_signed = true;
	else
		throw AForm::GradeTooLowException();
}

AForm::AForm(): m_name("Denied"), m_signed(false), m_sign_grade(150), m_execute_grade(1)
{
	check_grade(m_sign_grade);
	check_grade(m_execute_grade);
	// std::cout << "Form " << m_name << " has been created. Sign grade: " << m_sign_grade << ", Execute grade: " << m_execute_grade << '\n';
}

AForm::AForm(const std::string& name, int sign_grade, int execute_grade): m_name(name), m_signed(false), m_sign_grade(sign_grade), m_execute_grade(execute_grade)
{
	check_grade(m_sign_grade);
	check_grade(m_execute_grade);
	// std::cout << "Form " << m_name << " has been created. Sign grade: " << m_sign_grade << ", Execute grade: " << m_execute_grade << '\n';
}

AForm::AForm(const AForm& other): m_name(other.m_name), m_signed(other.m_signed), m_sign_grade(other.m_sign_grade), m_execute_grade(other.m_execute_grade)
{
	// std::cout << *this << "has been copied.\n";
}

AForm& AForm::operator= (const AForm& other)
{
	// yeah that's not how it works

	if (this != &other)
	{
	// 	m_name = other.m_name;
	// 	m_signed = other.m_signed;
	// 	m_sign_grade = other.m_sign_grade;
	// 	m_execute_grade = other.m_execute_grade;
	}

	// throwing an exception instead
	throw AForm::CannotBeModifiedException();
}

AForm::~AForm()
{
	// std::cout << ORANGE << *this << "\nhas been destroyed.\n" << END;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Exception: grade too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Exception: grade too low!");
}

const char* AForm::CannotBeModifiedException::what() const throw()
{
	return ("Exception: object has unmodifiable attributes!");
}

std::ostream& operator<< (std::ostream& os, const AForm& AForm)
{
	os << "Form: " << AForm.get_name() << "\nStatus: " << (AForm.is_signed() ? "signed" : "not signed") << "\nSign grade: " << AForm.get_sign_grade() << "\nExecute grade: " << AForm.get_execute_grade(); // @jegoh my computer screen goes all the way till the end of this liiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiine
	return (os);
}