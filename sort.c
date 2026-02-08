/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zichajia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:04:06 by zichajia          #+#    #+#             */
/*   Updated: 2026/02/08 14:04:09 by zichajia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_position(t_stack **stack_a)
{
	t_stack	*tmp;
	int		max_val;
	int		max_pos;
	int		counter;

	if (!stack_a || !*stack_a)
		return (-1);
	tmp = *stack_a;
	max_val = tmp->content;
	max_pos = 0;
	counter = 0;
	while (tmp != NULL)
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

int	sorted(t_stack **stack_a)
{
	t_stack	*tmp;

	if (!stack_a || !*stack_a)
		return (1);
	tmp = *stack_a;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	min_position(t_stack **stack)
{
	t_stack	*tmp;
	int		min_val;
	int		min_pos;
	int		i;

	tmp = *stack;
	min_val = tmp->content;
	min_pos = 0;
	i = 0;
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
	return (min_pos);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	if (size == 2)
		sort2(stack_a);
	else if (size == 3)
		sort3(stack_a);
	else if (size == 4)
		sort4(stack_a, stack_b);
	else if (size == 5)
		sort5(stack_a, stack_b);
}
