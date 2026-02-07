#include "push_swap.h"

char	*ftt_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

void	free_stack(list_t *stack)
{
	list_t	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

void	create_stack_a(char **two_d, list_t **list, char *args)
{
	int	i;

	i = 0;
	while (two_d[i])
	{
		add_back(list, ff_atoi(two_d[i], *list, two_d, args));
		i++;
	}
}
