/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zichajia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:47:56 by zichajia          #+#    #+#             */
/*   Updated: 2026/02/08 15:48:04 by zichajia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*second;

	first = *stack_a;
	second = first->next;
	if (first->content > second->content)
		sa(stack_a);
}

void	sort3(t_stack **stack_a)
{
	int	max_pos;

	if (sorted(stack_a))
		return ;
	max_pos = max_position(stack_a);
	if (max_pos == 0)
		ra(stack_a);
	else if (max_pos == 1)
		rra(stack_a);
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a);
}

void	sort4(t_stack **stack_a, t_stack **stack_b)
{
	int	max_pos;

	if (sorted(stack_a))
		return ;
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

void	push_min_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	pos;

	size = stack_size(*stack_a);
	pos = min_position(stack_a);
	if (size == 5 && pos == 1)
		ra(stack_a);
	else if (size == 5 && pos == 2)
		(ra(stack_a), ra(stack_a));
	else if (size == 5 && pos == 3)
		(rra(stack_a), rra(stack_a));
	else if (size == 5 && pos == 4)
		rra(stack_a);
	else if (size == 4 && pos == 1)
		ra(stack_a);
	else if (size == 4 && pos == 2)
		(ra(stack_a), ra(stack_a));
	else if (size == 4 && pos == 3)
		rra(stack_a);
	pb(stack_a, stack_b);
}

void	sort5(t_stack **stack_a, t_stack **stack_b)
{
	if (sorted(stack_a))
		return ;
	push_min_to_b(stack_a, stack_b);
	push_min_to_b(stack_a, stack_b);
	sort3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a);
}
