#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
	public:
		const std::string& getName() const;
		int getGrade() const;

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

		class CannotBeModifiedException: public std::exception
		{
			public:
				const char* what() const throw();
		};

		Bureaucrat();
		Bureaucrat(int grade);
		Bureaucrat(const std::string& name);
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator= (const Bureaucrat& other);
		~Bureaucrat();

	private:
		const std::string m_name;
		int m_grade;
};

std::ostream& operator<< (std::ostream& os, const Bureaucrat& bureaucrat);

#endif
