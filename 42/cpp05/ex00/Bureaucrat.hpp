#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
	public:
		const std::string& getName() const;
		const std::string& getGrade() const;

		void increment();
		void decrement();

		class GradeTooHighException: public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const throw();
		};

		Bureaucrat();
		Bureaucrat(int grade);
		Bureaucrat(const std::string& name);
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat& operator= (const Bureaucrat& other);
		~Bureaucrat();

	private:
		const std::string& m_name;
		int m_grade;
};

#endif

Bureaucrat::Bureaucrat(): m_name("Snoopy"), m_grade(150)
{
	std::cout << "Bureaucrat constructed\nName: " << m_name << "\nGrade:" << m_grade << '\n';
}

Bureaucrat::Bureaucrat(int grade): m_name("Snoopy"), m_grade(grade)
{
	std::cout << "Bureaucrat constructed\nName: " << m_name << "\nGrade:" << m_grade << '\n';
}

Bureaucrat::Bureaucrat(const std::string& name): m_name(name), m_grade(150)
{
	std::cout << "Bureaucrat constructed\nName: " << m_name << "\nGrade:" << m_grade << '\n';
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): m_name(name), m_grade(grade)
{
	std::cout << "Bureaucrat constructed\nName: " << m_name << "\nGrade:" << m_grade << '\n';
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