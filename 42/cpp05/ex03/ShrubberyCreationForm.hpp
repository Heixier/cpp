#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	public:
		void execute(const Bureaucrat& executor) const;
		// AForm* clone(const std::string& target) const;

		ShrubberyCreationForm(); // literally contradictory requirements
		ShrubberyCreationForm(const std::string& target); // OCF unless explicitly stated otherwise. ONE parameter in their constructor (SINGULAR)
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator= (const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

	private:
		std::string m_target;
};

#endif