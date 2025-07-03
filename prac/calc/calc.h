#ifndef CALC_H
# define CALC_H

int	get_user_input();
char	get_operator();
double	calculate(double first, char op, double second);
void	print_result(double result);

#endif