/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zichajia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:02:47 by zichajia          #+#    #+#             */
/*   Updated: 2026/02/08 14:02:51 by zichajia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate_stack_a(t_stack **stack_a)
{
	t_stack	*last;
	t_stack	*prev;

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

int	reverse_rotate_stack_b(t_stack **stack_b)
{
	t_stack	*last;
	t_stack	*prev;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return (0);
	prev = NULL;
	last = *stack_b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	return (1);
}

int	rra(t_stack **stack_a)
{
	if (!reverse_rotate_stack_a(stack_a))
		return (-1);
	ft_putstr("rra\n");
	return (0);
}

int	rrb(t_stack **stack_b)
{
	if (!reverse_rotate_stack_b(stack_b))
		return (-1);
	ft_putstr("rrb\n");
	return (0);
}

int	rrr(t_stack **stack_a, t_stack **stack_b, int index)
{
	if (!reverse_rotate_stack_a(stack_a) && !reverse_rotate_stack_b(stack_b))
		return (-1);
	if (index == 0)
		ft_putstr("rrr\n");
	return (0);
}
