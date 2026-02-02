#include "push_swap.h"

int rotate_stack_a(list_t **stack_a)
{
    if (!stack_a || !(*stack_a) || !((*stack_a)->next))
		return 0;
    list_t *first;
    list_t *last;

    first = *stack_a;
    last = *stack_a;

    while(last->next)
    last = last->next;

    *stack_a = first->next;
    last->next = first;
    first->next = NULL;
    
    return 1;

}

int rotate_stack_b(list_t **stack_b)
{
    if (!stack_b || !(*stack_b) || !((*stack_b)->next))
		return 0;
    list_t *first;
    list_t *last;

    first = *stack_b;
    last = *stack_b;

    while(last->next)
    last = last->next;

    *stack_b = first->next;
    last->next = first;
    first->next = NULL;
    
    return 1;

}

int	ra(list_t **stack_a)
{
	if (!rotate_stack_a(stack_a))
		return (-1);
	ft_putstr("ra\n");
	return (0);
}

int	rb(list_t **stack_b)
{
	if (!rotate_stack_b(stack_b))
		return (-1);
	ft_putstr("rb\n");
	return (0);
}

int	rr(list_t **stack_a, list_t **stack_b, int index)
{
	if (!rotate_stack_a(stack_a) && !rotate_stack_b(stack_b))
		return (-1);
	if (index == 0)
		ft_putstr("rr\n");
	return (0);
}