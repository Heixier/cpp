#include <iostream>
#include <iomanip>
#include <cstring>

int	get_user_input()
{
	std::cout << "Enter an integer: ";
	int	input;
	std::cin >> input;
	return (input);
}

char	get_operator()
{
	std::cout << "Enter a mathematical operator (+-*/): ";
	char	output;
	std::cin >> output;
	std::cout << "Operator: " << output << '\n';
	if (!strchr("+-*/", output))
		return (std::cout << "Invalid operator: " << output << '\n', NULL);
	return (output);
}

double	calculate(double first, char op, double second)
{
	switch(op)
	{
		case '+':
			return (first + second);
		case '-':
			return (first - second);
		case '*':
			return (first * second);
		case '/':
			return (first / second);
		default:
			return (0);
	}
}

void	print_result(double result)
{
	std::cout << "Result: " << std::setprecision (3) << result << '\n';
}
