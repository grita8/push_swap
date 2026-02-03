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


void free_stack(list_t *stack)
{
    list_t *tmp;

    while (stack)
    {
        tmp = stack->next;
        free(stack);
        stack = tmp;
    }
}



list_t *creat_stack(int argc, char **argv)
{
    list_t *stack = NULL;
    int i = 1;

    while (i < argc)
    {
        add_back(&stack, new_node(ft_atoi(argv[i])));
        i++;
    }
    return stack;
}

list_t *creat_stack_from_split(char **two_d, list_t *stack, char **all_args, char *joined_args)
{
    // list_t *stack = NULL;
    int i = 0;

    while (two_d[i])
    {
        add_back(&stack, new_node(ff_atoi(two_d[i], stack, all_args, joined_args)));
        i++;
    }
    return stack;
}