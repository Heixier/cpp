#ifndef INTERN_HPP
#define INTERN_HPP

#include <exception>
#include <iostream>

#include "AForm.hpp"

// Turn this fella into MateriaSource
class Intern
{
	public:
		AForm* makeForm(const std::string& name, const std::string& target) const;

		AForm* create_shrubbery_form(const std::string& target) const;
		AForm* create_robotomy_form(const std::string &target) const;
		AForm* create_presidential_form(const std::string &target) const;

		Intern();
		Intern(const Intern& other);
		Intern& operator= (const Intern& other);
		~Intern();

		// class InvalidFormException: public std::exception
		// {
		// 	const char* what() const throw();
		// };
		
	private:
		// AForm* learned_forms[3];
};

#endif