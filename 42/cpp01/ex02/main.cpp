#include <iostream>
#include <iomanip>

void	print_addresses(const std::string& base, const std::string& base_ref, const std::string *base_ptr)
{
	std::cout << '\n';
	std::cout << "\e[38;5;105;1mMemory addresses\e[0m\n";
	std::cout << std::left << std::setw(16) << "String variable" << ": " << &base << '\n';
	std::cout << std::left << std::setw(16) << "String pointer" << ": " << base_ptr << '\n';
	std::cout << std::left << std::setw(16) << "String reference" << ": " << &base_ref << '\n';
	std::cout << '\n';
}

void	print_values(const std::string& base, const std::string& base_ref, const std::string *base_ptr)
{
	std::cout << "\e[38;5;123;1mValues\e[0m\n";
	std::cout << std::left << std::setw(16) << "String variable" << ": " << base << '\n';
	std::cout << std::left << std::setw(16) << "String pointer" << ": " << *base_ptr << '\n';
	std::cout << std::left << std::setw(16) << "String reference" << ": " << base_ref << '\n';
	std::cout << '\n';
}

int main(void)
{
	std::string base = "HI THIS IS BRAIN";
	std::string* base_ptr = &base;
	std::string& base_ref = base;

	print_addresses(base, base_ref, base_ptr);
	print_values(base, base_ref, base_ptr);
}
