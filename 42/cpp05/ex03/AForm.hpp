#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>

#include "colors.hpp"

class Bureaucrat;

class AForm
{
	public:
		const std::string& get_name() const;
		bool is_signed() const;
		int get_sign_grade() const;
		int get_execute_grade() const;
		void beSigned(const Bureaucrat& signee);
		virtual void execute(const Bureaucrat& executor) const = 0;
		// virtual AForm* clone(const std::string& target) const = 0;
	
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
		virtual ~AForm();

	protected:
		AForm();
		AForm(const std::string& name, int sign_grade, int execute_grade);
		AForm(const AForm& other);
		AForm& operator= (const AForm& other);

	private:
		const std::string m_name;
		bool m_signed;
		const int m_sign_grade;
		const int m_execute_grade;
};

std::ostream& operator<< (std::ostream& os, const AForm& AForm);

#endif
