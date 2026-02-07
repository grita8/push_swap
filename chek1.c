#include "push_swap.h"

void	is_lst_size(list_t **list, char **two_d, char *args)
{
	if (stack_size(*list) == 1)
	{
		free_stack(*list);
		ftt_free(two_d);
		free(args);
		exit(1);
	}
}

void	check(list_t **a, char **two_d, char *args)
{
	is_lst_size(a, two_d, args);
	check_is_duplicated(is_duplicated(*a), a, two_d, args);
	check_is_sorted(sorted(a), a, two_d, args);
}
