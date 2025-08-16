#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <fstream>

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > get_execute_grade())
		throw GradeTooLowException();
	std::ofstream shrubbery;
	shrubbery.open((m_target + "_shrubbery").c_str());
	shrubbery << "$> tree\n\
.\n\
├── ex00\n\
│   ├── Bureaucrat.cpp\n\
│   ├── Bureaucrat.hpp\n\
│   ├── colors.hpp\n\
│   ├── main.cpp\n\
│   └── Makefile\n\
├── ex01\n\
│   ├── Bureaucrat.cpp\n\
│   ├── Bureaucrat.hpp\n\
│   ├── colors.hpp\n\
│   ├── Form.cpp\n\
│   ├── Form.hpp\n\
│   ├── main.cpp\n\
│   └── Makefile\n\
├── ex02\n\
│   ├── AForm.cpp\n\
│   ├── AForm.hpp\n\
│   ├── Bureaucrat.cpp\n\
│   ├── Bureaucrat.hpp\n\
│   ├── colors.hpp\n\
│   ├── main.cpp\n\
│   ├── Makefile\n\
│   ├── PresidentialPardonForm.cpp\n\
│   ├── PresidentialPardonForm.hpp\n\
│   ├── RobotomyRequestForm.cpp\n\
│   ├── RobotomyRequestForm.hpp\n\
│   ├── ShrubberyCreationForm.cpp\n\
│   └── ShrubberyCreationForm.hpp\n\
└── ex03\n\
    ├── AForm.cpp\n\
    ├── AForm.hpp\n\
    ├── Bureaucrat.cpp\n\
    ├── Bureaucrat.hpp\n\
    ├── colors.hpp\n\
    ├── Intern.cpp\n\
    ├── Intern.hpp\n\
    ├── main.cpp\n\
    ├── Makefile\n\
    ├── PresidentialPardonForm.cpp\n\
    ├── PresidentialPardonForm.hpp\n\
    ├── RobotomyRequestForm.cpp\n\
    ├── RobotomyRequestForm.hpp\n\
    ├── ShrubberyCreationForm.cpp\n\
    └── ShrubberyCreationForm.hpp\n\
\n\
5 directories, 40 files\n\n\n\nNot happy isit? Ok fine\n\
  ,d                                      \n\
  88                                      \n\
MM88MMM 8b,dPPYba,  ,adPPYba,  ,adPPYba,  \n\
  88    88P'   \"Y8 a8P_____88 a8P_____88  \n\
  88    88         8PP\"\"\"\"\"\"\" 8PP\"\"\"\"\"\"\"  \n\
  88,   88         \"8b,   ,aa \"8b,   ,aa  \n\
  \"Y888 88          `\"Ybbd8\"'  `\"Ybbd8\"'  \n\
\n\
Still not happy?\n\n\n\n\
\n\
               ,@@@@@@@,\n\
       ,,,.   ,@@@@@@/@@,  .oo8888o.\n\
    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n\
   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n\
   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n\
   %&&%/ %&%%&&@\\ V /@@' `88\\8 `/88'\n\
   `&%\\ ` /%&'    |.|        \\ '|8'\n\
       |o|        | |         | |\n\
       |.|        | |         | |\n\
jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n\
\n\
               ,@@@@@@@,\n\
       ,,,.   ,@@@@@@/@@,  .oo8888o.\n\
    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n\
   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n\
   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n\
   %&&%/ %&%%&&@\\ V /@@' `88\\8 `/88'\n\
   `&%\\ ` /%&'    |.|        \\ '|8'\n\
       |o|        | |         | |\n\
       |.|        | |         | |\n\
jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n\
\n\
               ,@@@@@@@,\n\
       ,,,.   ,@@@@@@/@@,  .oo8888o.\n\
    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n\
   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n\
   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n\
   %&&%/ %&%%&&@\\ V /@@' `88\\8 `/88'\n\
   `&%\\ ` /%&'    |.|        \\ '|8'\n\
       |o|        | |         | |\n\
       |.|        | |         | |\n\
jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n\
\n\
               ,@@@@@@@,\n\
       ,,,.   ,@@@@@@/@@,  .oo8888o.\n\
    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n\
   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n\
   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n\
   %&&%/ %&%%&&@\\ V /@@' `88\\8 `/88'\n\
   `&%\\ ` /%&'    |.|        \\ '|8'\n\
       |o|        | |         | |\n\
       |.|        | |         | |\n\
jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n\
\n\
               ,@@@@@@@,\n\
       ,,,.   ,@@@@@@/@@,  .oo8888o.\n\
    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n\
   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n\
   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n\
   %&&%/ %&%%&&@\\ V /@@' `88\\8 `/88'\n\
   `&%\\ ` /%&'    |.|        \\ '|8'\n\
       |o|        | |         | |\n\
       |.|        | |         | |\n\
jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n\
\n\
               ,@@@@@@@,\n\
       ,,,.   ,@@@@@@/@@,  .oo8888o.\n\
    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n\
   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n\
   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n\
   %&&%/ %&%%&&@\\ V /@@' `88\\8 `/88'\n\
   `&%\\ ` /%&'    |.|        \\ '|8'\n\
       |o|        | |         | |\n\
       |.|        | |         | |\n\
jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n";

	shrubbery.close();
}


// AForm* ShrubberyCreationForm::clone(const std::string &target) const
// {
// 	AForm* copy = new ShrubberyCreationForm(target);
// 	return (copy);
// }

ShrubberyCreationForm::ShrubberyCreationForm(): AForm(), m_target("graveyard of the dementia patient who wrote this subject")
{
	std::cout << "I hope you never rest in peace\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("ShrubberyCreationForm", 145, 137), m_target(target)
{
	std::cout << "Shrubbery Creation Form has been created!\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other), m_target(other.m_target)
{
	std::cout << "Shrubbery Creation Form has been copied!\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other); // exception should be thrown
		m_target = other.m_target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery Creation Form has been destroyed!\n";
}
