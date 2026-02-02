#include "push_swap.h"
int reverse_rotate_stack_a(list_t **stack_a)
{
    list_t *last;
    list_t *prev;

    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return (0);

    prev = NULL;
    last = *stack_a;

    while (last->next)
    {
        prev = last;
        last = last->next;
    }

    prev->next = NULL;     
    last->next = *stack_a; 
    *stack_a = last;       
    return (1);
}

int reverse_rotate_stack_b(list_t **atack_b)
{
    list_t *last;
    list_t *prev;

    if (!atack_b || !*atack_b || !(*atack_b)->next)
        return (0);

    prev = NULL;
    last = *atack_b;

    while (last->next)
    {
        prev = last;
        last = last->next;
    }

    prev->next = NULL;    
    last->next = *atack_b;  
    *atack_b = last;        

    return (1);
}
int	rra(list_t **stack_a)
{
	if (!reverse_rotate_stack_a(stack_a))
		return (-1);
	ft_putstr("rra\n");
	return (0);
}

int	rrb(list_t **stack_b)
{
	if (!reverse_rotate_stack_b(stack_b))
		return (-1);
	ft_putstr("rrb\n");
	return (0);
}

int	rrr(list_t **stack_a, list_t **stack_b, int index)
{
	if (!reverse_rotate_stack_a(stack_a) && !reverse_rotate_stack_b(stack_b))
		return (-1);
	if (index == 0)
		ft_putstr("rrr\n");
	return (0);
}