#include "push_swap.h"

int	put_chunk(int len_a)
{
	int	chunk;

	if (len_a <= 100)
		chunk = len_a / 4;
	else if (len_a <= 500)
		chunk = len_a / 12;
	else
		chunk = len_a / 20;
	return (chunk);
}

void	increment(int *i, int *chunk, int len)
{
	if (*i < len - 1)
		(*i)++;
	if (*chunk < len - 1)
		(*chunk)++;
}

void	check_b(list_t **stack_b)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	if ((*stack_b)->content < (*stack_b)->next->content)
		sb(stack_b);
}

void	push_to_b(list_t **stack_a, list_t **stack_b, int *arr, int len_a)
{
	int	i;
	int	chunk;
	int	count;
	int	max_rot;

	i = 0;
	chunk = put_chunk(len_a);
	count = 0;
	max_rot = stack_size(*stack_a);
	while (*stack_a)
	{
		if ((*stack_a)->content <= arr[i])
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			increment(&i, &chunk, len_a);
			count = 0;
			max_rot = stack_size(*stack_a);
		}
		else if ((*stack_a)->content <= arr[chunk])
		{
			pb(stack_a, stack_b);
			increment(&i, &chunk, len_a);
			count = 0;
			max_rot = stack_size(*stack_a);
		}
		else
		{
			ra(stack_a);
			count++;
		}
		if (count >= max_rot)
		{
			pb(stack_a, stack_b);
			count = 0;
			max_rot = stack_size(*stack_a);
		}
	}
}

void	push_to_a(list_t **stack_a, list_t **stack_b)
{
	int	len_b;
	int	p;

	if (!stack_a || !stack_b || !*stack_b)
		return ;
	len_b = stack_size(*stack_b);
	while (len_b > 0)
	{
		p = max_position(stack_b);
		if (p <= len_b / 2)
		{
			while (p-- > 0)
				rb(stack_b);
		}
		else
		{
			while (p++ < len_b)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
		len_b--;
	}
}
