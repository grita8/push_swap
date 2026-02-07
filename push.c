#include "push_swap.h"

int	push_a(list_t **stack_a, list_t **stack_b)
{
	list_t	*tmp;

	if (!stack_b || !(*stack_b))
		return (0);
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	return (1);
}

int	push_b(list_t **stack_a, list_t **stack_b)
{
	list_t	*tmp;

	if (!stack_a || !(*stack_a))
		return (0);
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	return (1);
}

int	pa(list_t **stack_a, list_t **stack_b)
{
	if (!push_a(stack_a, stack_b))
		return (-1);
	ft_putstr("pa\n");
	return (0);
}

int	pb(list_t **stack_a, list_t **stack_b)
{
	if (!push_b(stack_a, stack_b))
		return (-1);
	ft_putstr("pb\n");
	return (0);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

