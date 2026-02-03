#include "push_swap.h"

void sort2(list_t **stack_a)
{
    list_t *first;
    list_t *second;

    first = *stack_a;
    second = first->next;

    if (first->content > second->content)
        sa(stack_a);
}

void sort3(list_t **stack_a)
{
    int max_pos;

    if (sorted(stack_a))
        return;

    max_pos = max_position(stack_a);
    if (max_pos == 0)
    {
        ra(stack_a);
    }
    else if (max_pos == 1)
    {
        rra(stack_a);
    }
    if ((*stack_a)->content > (*stack_a)->next->content)
    {
        sa(stack_a);
    }
}

void sort4(list_t **stack_a, list_t **stack_b)
{
    int max_pos;

    if (sorted(stack_a))
        return;

    max_pos = max_position(stack_a);

    if (max_pos == 1)
        ra(stack_a);
    else if (max_pos == 2)
    {
        ra(stack_a);
        ra(stack_a);
    }
    else if (max_pos == 3)
        rra(stack_a);
        
    pb(stack_a, stack_b);
    sort3(stack_a);
    pa(stack_a, stack_b);
    ra(stack_a);
}


void push_min_to_b(list_t **stack_a, list_t **stack_b)
{
    int size = stack_size(*stack_a);
    int pos = min_position(stack_a);

    if (size == 5)
    {
        if (pos == 1)
            ra(stack_a);
        else if (pos == 2)
        {
            ra(stack_a);
            ra(stack_a);
        }
        else if (pos == 3)
        {
            rra(stack_a);
            rra(stack_a);
        }
        else if (pos == 4)
            rra(stack_a);
    }
    else if (size == 4)
    {
        if (pos == 1)
            ra(stack_a);
        else if (pos == 2)
        {
            ra(stack_a);
            ra(stack_a);
        }
        else if (pos == 3)
            rra(stack_a);
    }
    pb(stack_a, stack_b);
}
void sort5(list_t **stack_a, list_t **stack_b)
{
    if (sorted(stack_a))
        return;

    push_min_to_b(stack_a, stack_b);
    push_min_to_b(stack_a, stack_b);

    sort3(stack_a);

    pa(stack_a, stack_b);
    pa(stack_a, stack_b);

    if ((*stack_a)->content > (*stack_a)->next->content)
        sa(stack_a);
}
