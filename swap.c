/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zichajia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:05:10 by zichajia          #+#    #+#             */
/*   Updated: 2026/02/08 14:05:23 by zichajia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_stack_a(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*second;

	if ((!stack_a) || !(*stack_a) || !((*stack_a)->next))
		return (0);
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	return (1);
}

int	swap_stack_b(t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack_b || !(*stack_b) || !((*stack_b)->next))
		return (0);
	first = *stack_b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
	return (1);
}

int	sa(t_stack **stack_a)
{
	if (!swap_stack_a(stack_a))
		return (-1);
	ft_putstr("sa\n");
	return (0);
}

int	sb(t_stack **stack_b)
{
	if (!swap_stack_b(stack_b))
		return (-1);
	ft_putstr("sb\n");
	return (0);
}

int	ss(t_stack **stack_a, t_stack **stack_b, int index)
{
	if (!swap_stack_a(stack_a) && !swap_stack_b(stack_b))
		return (-1);
	if (index == 0)
		ft_putstr("ss\n");
	return (0);
}
