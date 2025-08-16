#include <iostream>
#include <exception>
#include <unistd.h>

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "colors.hpp"

static void test_create(const std::string& name, int sign_grade, int exec_grade)
{
	try
	{
		std::cout << "\nTrying to create a Form " << name << " with a signing grade of " <<sign_grade << " and an execute grade of " << exec_grade << ":\n";
		Form test(name, sign_grade, exec_grade);
		std::cout << LIGHT_GREEN << "Success!\n" << END;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << '\n' << END;
	}
}

static void work_and_sign(Bureaucrat& worker, Form& form, bool increment)
{
	while (true)
	{
		std::cout << ICE_BLUE << worker << '\n' << END;
		try
		{
			if (worker.signForm(form))
				break;
			increment == true ? worker.increment() : worker.decrement();
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << '\n' << END;
			break;
		}
		sleep(1);
	}
}

int main(void)
{
	try
	{
		Form original;
		Form copy(original);
		original = copy;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << '\n' << END;
	}

	test_create("Loan", 2, 150);
	test_create("Rent", 75, 150);
	test_create("Tax", -5, -1);
	test_create("Bill", 100000, 1000000);

	Bureaucrat alex("Alex", 135);
	Form mortgage("Mortgage", 130, 150);
	work_and_sign(alex, mortgage, true);
}