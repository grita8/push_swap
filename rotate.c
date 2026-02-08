/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zichajia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:03:48 by zichajia          #+#    #+#             */
/*   Updated: 2026/02/08 14:03:52 by zichajia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_stack_a(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack_a || !(*stack_a) || !((*stack_a)->next))
		return (0);
	first = *stack_a;
	last = *stack_a;
	while (last->next)
		last = last->next;
	*stack_a = first->next;
	last->next = first;
	first->next = NULL;
	return (1);
}

int	rotate_stack_b(t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack_b || !(*stack_b) || !((*stack_b)->next))
		return (0);
	first = *stack_b;
	last = *stack_b;
	while (last->next)
		last = last->next;
	*stack_b = first->next;
	last->next = first;
	first->next = NULL;
	return (1);
}

int	ra(t_stack **stack_a)
{
	if (!rotate_stack_a(stack_a))
		return (-1);
	ft_putstr("ra\n");
	return (0);
}

int	rb(t_stack **stack_b)
{
	if (!rotate_stack_b(stack_b))
		return (-1);
	ft_putstr("rb\n");
	return (0);
}

int	rr(t_stack **stack_a, t_stack **stack_b, int index)
{
	if (!rotate_stack_a(stack_a) && !rotate_stack_b(stack_b))
		return (-1);
	if (index == 0)
		ft_putstr("rr\n");
	return (0);
}
