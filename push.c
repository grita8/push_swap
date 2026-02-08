/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zichajia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:02:18 by zichajia          #+#    #+#             */
/*   Updated: 2026/02/08 14:02:21 by zichajia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!stack_b || !(*stack_b))
		return (0);
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	return (1);
}

int	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!stack_a || !(*stack_a))
		return (0);
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	return (1);
}

int	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (!push_a(stack_a, stack_b))
		return (-1);
	ft_putstr("pa\n");
	return (0);
}

int	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (!push_b(stack_a, stack_b))
		return (-1);
	ft_putstr("pb\n");
	return (0);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}
