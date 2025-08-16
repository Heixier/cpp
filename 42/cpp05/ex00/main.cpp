#include <iostream>
#include <exception>
#include <unistd.h>

#include "Bureaucrat.hpp"
#include "colors.hpp"

static void test_create(const std::string& name, int grade)
{
	try
	{
		std::cout << "\nTrying to create a Bureaucrat named " << name << " with a grade of " << grade << ":\n";
		Bureaucrat test(name, grade);
		std::cout << LIGHT_GREEN << "Success!\n" << END;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << END << std::endl;
	}
}

static void work(Bureaucrat& worker, bool increment)
{
	while (true)
	{
		std::cout << ICE_BLUE << worker << END << std::endl;
		try
		{
			increment == true ? worker.increment() : worker.decrement();
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << END << std::endl;
			break;
		}
		sleep(1);
	}
}

int main(void)
{
	try
	{
		Bureaucrat original;
		Bureaucrat copy(original);
		original = copy;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << END << std::endl;
	}

	test_create("John", 2);
	test_create("Alex", 150);
	test_create("James", -5);
	test_create("Jane", 1000000);

	Bureaucrat mary("Mary", 5);
	work(mary, true);

	Bureaucrat alex("Alex", 145);
	work(alex, false);

}