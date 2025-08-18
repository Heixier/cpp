#include "Form.hpp"
#include "Bureaucrat.hpp"

#include "colors.hpp"

static void check_grade(int grade)
{
	if (grade > 150)
		throw Form::GradeTooLowException();
	if (grade < 1)
		throw Form::GradeTooHighException();
}

const std::string& Form::get_name() const
{
	return (m_name);
}

bool Form::is_signed() const
{
	return (m_signed);
}

int Form::get_sign_grade() const
{
	return (m_sign_grade);
}

int Form::get_execute_grade() const
{
	return (m_execute_grade);
}

void Form::beSigned(const Bureaucrat& signee)
{
	if (signee.getGrade() <= m_sign_grade)
		m_signed = true;
	else
		throw Form::GradeTooLowException();
}

Form::Form(): m_name("Denied"), m_signed(false), m_sign_grade(150), m_execute_grade(1)
{
	check_grade(m_sign_grade);
	check_grade(m_execute_grade);
	std::cout << "Form " << m_name << " has been created. Sign grade: " << m_sign_grade << ", Execute grade: " << m_execute_grade << '\n';
}

Form::Form(const std::string& name, int sign_grade, int execute_grade): m_name(name), m_signed(false), m_sign_grade(sign_grade), m_execute_grade(execute_grade)
{
	check_grade(m_sign_grade);
	check_grade(m_execute_grade);
	std::cout << "Form " << m_name << " has been created. Sign grade: " << m_sign_grade << ", Execute grade: " << m_execute_grade << '\n';
}

Form::Form(const Form& other): m_name(other.m_name), m_signed(other.m_signed), m_sign_grade(other.m_sign_grade), m_execute_grade(other.m_execute_grade)
{
	std::cout << *this << " has been copied.\n";
}

Form& Form::operator= (const Form& other)
{
	(void)other;
	throw Form::CannotBeModifiedException();
}

Form::~Form()
{
	std::cout << ORANGE << *this << "\nhas been destroyed.\n" << END;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Exception: grade too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Exception: grade too low!");
}

const char* Form::CannotBeModifiedException::what() const throw()
{
	return ("Exception: object has unmodifiable attributes!");
}

std::ostream& operator<< (std::ostream& os, const Form& form)
{
	os << "FORM:\nName: " << form.get_name() << "\nStatus: " << (form.is_signed() ? "signed" : "not signed") << "\nSign grade: " << form.get_sign_grade() << "\nExecute grade: " << form.get_execute_grade(); // @jegoh my computer screen goes all the way till the end of this liiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiine
	return (os);
}