#include <iostream>
#include "calc.h"

int	main()
{
	int	value = get_user_input();
	char	op = get_operator();
	if (!op)
		return (1);
	int	second_val = get_user_input();
	double	result = calculate(value, op, second_val);
	print_result(result);
}
