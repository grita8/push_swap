#include "push_swap.h"

int	is_it_alpha(char *str, int *i)
{
	if (!str[*i])
		return (1);
	while (str[*i])
	{
		if (!(((str[*i] >= '0' && str[*i] <= '9'))))
		{
			return (1);
		}
		(*i)++;
	}
	return (0);
}

void	check_int_overflow(long number, list_t *list, char **two_d,
		char *args)
{
	if (number > INT_MAX || number < INT_MIN)
	{
		write(2, "Error\n", 6);
	    free_stack(list);
		ftt_free(two_d);
		free(args);
		exit(1);
	}
}

void	else_of_atoi(list_t **list, char **two_d, char *args)
{
	write(2, "Error\n", 6);
	free_stack(*list);
	ftt_free(two_d);
	free(args);
	exit(1);
}

void	init_vars(t_atoa_state *vars)
{
	vars->i = 0;
	vars->result = 0;
	vars->signe = 1;
}
int	ff_atoi(char *str, list_t *list, char **two_d, char *args)
{
    long result = 0;
    int sign = 1;
    int i = 0;
    int digit_found = 0;

    // Skip leading whitespace
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
           str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
        i++;

    // Handle optional sign
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }

    // Main digit loop
    while (str[i] >= '0' && str[i] <= '9')
    {
        digit_found = 1;
        result = result * 10 + (str[i] - '0');
        check_int_overflow(result * sign, list, two_d, args);
        i++;
    }

    // If no digits found --> error/exit
    if (!digit_found)
        else_of_atoi(&list, two_d, args);

    // After number, ONLY whitespace allowed, else error/exit
    while (str[i])
    {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' &&
            str[i] != '\v' && str[i] != '\f' && str[i] != '\r')
            else_of_atoi(&list, two_d, args);
        i++;
    }

    return ((int)(result * sign));
}