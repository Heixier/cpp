#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>

#include "colors.hpp"

class Bureaucrat;

class Form
{
	public:
		const std::string& get_name() const;
		bool is_signed() const;
		int get_sign_grade() const;
		int get_execute_grade() const;
		void beSigned(const Bureaucrat& signee);

		Form();
		Form(const std::string& name, int sign_grade, int execute_grade);
		Form(const Form& other);
		Form& operator= (const Form& other);
		~Form();

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

	private:
		const std::string m_name;
		bool m_signed;
		const int m_sign_grade;
		const int m_execute_grade;
};

std::ostream& operator<< (std::ostream& os, const Form& form);

#endif
