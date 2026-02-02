#include "push_swap.h"

int swap_stack_a(list_t **stack_a)
{
	list_t *first = *stack_a;
	list_t *second = first->next;

	if ((!stack_a) || !(*stack_a) || !((*stack_a)->next))
		return 0;
	// [A | first->next] -> [B| second->next] ->  [C| x]
	first->next = second->next; // A -> c    [a | second->next] -> [C| x]       ||  [D | vide]
	second->next = first;		// [B| first->next]      B -> A -> C
	*stack_a = second;
	return (1);
}

int swap_stack_b(list_t **stack_b)
{
	list_t *first = *stack_b;
	list_t *second = first->next;

	if (!stack_b || !(*stack_b) || !((*stack_b)->next))
		return 0;

	first->next = second->next;
	second->next = first;
	*stack_b = second;
	return (1);
}

int sa(list_t **stack_a)
{
	if (!swap_stack_a(stack_a))
		return (-1);
	ft_putstr("sa\n");
	return (0);
}

int sb(list_t **stack_b)
{
	if (!swap_stack_b(stack_b))
		return (-1);
	ft_putstr("sb\n");
	return (0);
}

int ss(list_t **stack_a, list_t **stack_b, int index)
{
	if (!swap_stack_a(stack_a) && !swap_stack_b(stack_b))
		return (-1);
	if (index == 0)
		ft_putstr("ss\n");
	return (0);
}
