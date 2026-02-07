#include "push_swap.h"

int	is_sorted(list_t *list)
{
	while (list->next)
	{
		if (list->content > list->next->content)
			return (0);
		list = list->next;
	}
	return (1);
}

int	stack_size(list_t *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	check_is_sorted(int value, list_t **list, char **two_d, char *args)
{
	if (value)
	{
		free_stack(*list);
		ftt_free(two_d);
		free(args);
		exit(0);
	}
}

void	check_is_duplicated(int value, list_t **list, char **two_d, char *args)
{
	if (value)
	{
		write(2, "Error\n", 6);
		free_stack(*list);
		ftt_free(two_d);
		free(args);
		exit(1);
	}
}

int	is_duplicated(list_t *list)
{
	list_t	*tmp1;
	list_t	*tmp2;

	tmp1 = list;
	while (tmp1 != NULL)
	{
		tmp2 = tmp1->next;
		while (tmp2 != NULL)
		{
			if (tmp2->content == tmp1->content)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (0);
}
