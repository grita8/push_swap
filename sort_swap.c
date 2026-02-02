#include "push_swap.h"

// Find position of maximum element (0 = top)
 
{
    t_list *current;
    int max_index;
    int max_pos;
    int pos;
    
    current = *stack;
    max_index = current->index;
    max_pos = 0;
    pos = 0;
    
    while (current)
    {
        if (current->index > max_index)
        {
            max_index = current->index;
            max_pos = pos;
        }
        current = current->next;
        pos++;
    }
    return (max_pos);
}

// Sort 2 elements
void sort_2(t_list **stack_a)
{
    t_list *first;
    
    first = *stack_a;
    
    if (first->index > first->next->index)
        sa(stack_a);
}

// Sort 3 elements - simple method
void sort_3_simple(t_list **stack_a)
{
    int max_pos;
    t_list *first;
    
    if (is_sorted(stack_a))
        return;
    
    // Find biggest element position
    max_pos = find_max_position(stack_a);
    
    // Move biggest to bottom
    if (max_pos == 0)
    {
        // Max at top, rotate to bottom
        ra(stack_a);
        ra(stack_a);
    }
    else if (max_pos == 1)
    {
        // Max in middle, reverse rotate
        rra(stack_a);
    }
    // If max_pos == 2, already at bottom
    
    // Check if sorted now
    if (is_sorted(stack_a))
        return;
    
    // Fix top 2 elements if needed
    first = *stack_a;
    if (first->index > first->next->index)
        sa(stack_a);
}

// Sort 4 elements
void sort_4_simple(t_list **stack_a, t_list **stack_b)
{
    int max_pos;
    
    if (is_sorted(stack_a))
        return;
    
    // Find and move max to top
    max_pos = find_max_position(stack_a);
    
    while (max_pos > 0)
    {
        ra(stack_a);
        max_pos--;
    }
    
    // Push max to stack_b
    pb(stack_a, stack_b);
    
    // Sort remaining 3 elements
    sort_3_simple(stack_a);
    
    // Push max back
    pa(stack_a, stack_b);
    
    // Rotate max to bottom
    ra(stack_a);
    ra(stack_a);
    ra(stack_a);
}

// Sort 5 elements
void sort_5_simple(t_list **stack_a, t_list **stack_b)
{
    int max_pos;
    
    if (is_sorted(stack_a))
        return;
    
    // Find and move max to top
    max_pos = find_max_position(stack_a);
    
    while (max_pos > 0)
    {
        ra(stack_a);
        max_pos--;
    }
    
    // Push max to stack_b
    pb(stack_a, stack_b);
    
    // Sort remaining 4 elements
    sort_4_simple(stack_a, stack_b);
    
    // Push max back
    pa(stack_a, stack_b);
    
    // Rotate max to bottom
    ra(stack_a);
    ra(stack_a);
    ra(stack_a);
    ra(stack_a);
}

// Main sorting function
void simple_sort_v2(t_list **stack_a, t_list **stack_b)
{
    int size;
    
    if (is_sorted(stack_a))
        return;
    
    size = ft_lstsize(*stack_a);
    
    if (size == 2)
        sort_2(stack_a);
    else if (size == 3)
        sort_3_simple(stack_a);
    else if (size == 4)
        sort_4_simple(stack_a, stack_b);
    else if (size == 5)
        sort_5_simple(stack_a, stack_b);
}