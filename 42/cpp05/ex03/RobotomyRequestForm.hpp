#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	public:
		void execute(const Bureaucrat& executor) const;
		// AForm* clone(const std::string& target) const;

		RobotomyRequestForm(); // literally contradictory requirements
		RobotomyRequestForm(const std::string& target); // OCF unless explicitly stated otherwise. ONE parameter in their constructor (SINGULAR)
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator= (const RobotomyRequestForm& other);
		~RobotomyRequestForm();

	private:
		std::string m_target;
};

#endif