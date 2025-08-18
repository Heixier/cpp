#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	public:
		void execute(const Bureaucrat& executor) const;

		ShrubberyCreationForm(const std::string& target); // OCF unless explicitly stated otherwise. ONE parameter in their constructor (SINGULAR)
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

	private:
		std::string m_target;

		ShrubberyCreationForm();
		ShrubberyCreationForm& operator= (const ShrubberyCreationForm& other);
};

#endif