/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zichajia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:59:10 by zichajia          #+#    #+#             */
/*   Updated: 2026/02/08 13:59:15 by zichajia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *list)
{
	while (list->next)
	{
		if (list->content > list->next->content)
			return (0);
		list = list->next;
	}
	return (1);
}

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	check_is_sorted(int value, t_stack **list, char **two_d, char *args)
{
	if (value)
	{
		free_stack(*list);
		ftt_free(two_d);
		free(args);
		exit(0);
	}
}

void	check_is_duplicated(int value, t_stack **list, char **two_d, char *args)
{
	if (value)
	{
		write(2, "Error\n", 6);
		free_stack(*list);
		ftt_free(two_d);
		free(args);
		exit(1);
	}
}

int	is_duplicated(t_stack *list)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = list;
	while (tmp1 != NULL)
	{
		tmp2 = tmp1->next;
		while (tmp2 != NULL)
		{
			if (tmp2->content == tmp1->content)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (0);
}
