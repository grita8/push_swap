#include "push_swap.h"

int sorted(list_t **stack_a)
{
    list_t *tmp;

    if (!stack_a || !*stack_a)
        return (1);

    tmp = *stack_a;
    while (tmp->next)
    {
        if (tmp->content > tmp->next->content)
        {
            return (0);
        }
        tmp = tmp->next;
    }
    return (1);
}
void sort2(list_t **stack_a)
{
    list_t *first;
    list_t *second;

    first = *stack_a;
    second = first->next;

    if (first->content > second->content)
        sa(stack_a);
}

int max_position(list_t **stack_a)
{
    list_t *tmp;
    tmp = *stack_a;

    if (!stack_a || !*stack_a)
        return (-1);

    int max_val = tmp->content;
    int max_pos = 0;
    int counter = 0;

    while (tmp)
    {
        if (tmp->content > max_val)
        {
            max_val = tmp->content;
            max_pos = counter;
        }
        tmp = tmp->next;
        counter++;
    }
    return (max_pos);
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
int min_position(list_t **stack)
{
    list_t *tmp = *stack;
    int min_val = tmp->content;
    int min_pos = 0, i = 0;
    while (tmp)
    {
        if (tmp->content < min_val)
        {
            min_val = tmp->content;
            min_pos = i;
        }
        tmp = tmp->next;
        i++;
    }
    return min_pos;
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
