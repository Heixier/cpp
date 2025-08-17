#include <iostream>
#include <exception>
#include <unistd.h>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

#include "colors.hpp"

int main(void)
{
	AForm* temp = NULL;

	std::cout << ICE_BLUE << "\n>>> HIRING ALICE FOR $60/h\n";
	Bureaucrat daughter_of_the_nephew_in_law_of_the_ceo("Alice", 2);
	std::cout << END;

	std::cout << ICE_BLUE << "\n>>> HIRING CHANDRA FOR $10/h\n";
	Bureaucrat minimum_wage_worker_from_poor_village_who_works_much_harder_than_anyone_else("Chandra", 138);
	std::cout << END;

	std::cout << YELLOW << "\n>>> HIRING UNI KID FOR \"WORK EXPERIENCE\"/h\n" << END;
	Intern* bro = new Intern();

	std::cout << YELLOW << "\n>>> COPYING INTERN BECAUSE MORE IS BETTER\n" << END;
	Intern* copy = new Intern(*bro);

	std::cout << YELLOW << "\n>>> ACTUALLY WE CAN'T AFFORD THIS FREE INTERN\n" << END;
	*bro = *copy;
	delete copy;

	std::cout << YELLOW << "\n>>> TEST: CAN SIGN BUT CANNOT EXECUTE:\n\n" << END;
	temp = bro -> makeForm("shrubbery creation", "Munich");
	std::cout << ICE_BLUE << "\n>>> GET CHANDRA TO SIGN AND (FAIL TO) EXECUTE\n" << END;

	minimum_wage_worker_from_poor_village_who_works_much_harder_than_anyone_else.signForm(*temp);
	minimum_wage_worker_from_poor_village_who_works_much_harder_than_anyone_else.executeForm(*temp);

	std::cout << YELLOW << "\n>>> BOSS CALLED TO HELP EXECUTE:\n\n" << END;
	daughter_of_the_nephew_in_law_of_the_ceo.executeForm(*temp);

	delete temp;

	std::cout << YELLOW << "\n>>> TEST: CANNOT SIGN AND CANNOT EXECUTE:\n\n" << END;
	temp = bro -> makeForm("presidential pardon", "Martin");
	std::cout << ICE_BLUE << "\n>>> GET CHANDRA TO (FAIL TO) SIGN AND (FAIL TO) EXECUTE\n" << END;

	minimum_wage_worker_from_poor_village_who_works_much_harder_than_anyone_else.signForm(*temp);
	minimum_wage_worker_from_poor_village_who_works_much_harder_than_anyone_else.executeForm(*temp);

	std::cout << YELLOW << "\n>>> BOSS CALLED TO HELP SIGN AND EXECUTE:\n\n" << END;

	daughter_of_the_nephew_in_law_of_the_ceo.signForm(*temp);
	daughter_of_the_nephew_in_law_of_the_ceo.executeForm(*temp);

	delete temp;
	
	std::cout << YELLOW << "\n>>> ASK INTERN TO MAKE NON_EXISTENT FORMS\n" << END;
	temp = bro -> makeForm("lmao", "so funny");
	temp = bro -> makeForm("your head", "in space");
	temp = bro -> makeForm("la", "walao");
	
	std::cout << YELLOW << "\n>>> INTERN FAILED AND GETS A ROBOTOMY\n" << END;
	temp = bro -> makeForm("robotomy request", "intern");

	daughter_of_the_nephew_in_law_of_the_ceo.signForm(*temp);
	daughter_of_the_nephew_in_law_of_the_ceo.executeForm(*temp);

	delete temp;

	std::cout << YELLOW << "\n>>> INTERN WANTS TO QUIT BUT GETS FIRED FIRST\n" << END;
	delete bro;

	std::cout << YELLOW << "\n>>> ACTUALLY EVERYONE GETS FIRED ANYWAY DUE TO COMPANY MERGER\n" << END;
}