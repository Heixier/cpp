#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	public:
		void execute(const Bureaucrat& executor) const;

		PresidentialPardonForm(const std::string& target); // OCF unless explicitly stated otherwise. ONE parameter in their constructor (SINGULAR)
		PresidentialPardonForm(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

	private:
		std::string m_target;

		PresidentialPardonForm();
		PresidentialPardonForm& operator= (const PresidentialPardonForm& other);
};

#endif
