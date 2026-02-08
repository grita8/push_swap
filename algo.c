/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zichajia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:58:46 by zichajia          #+#    #+#             */
/*   Updated: 2026/02/08 13:58:49 by zichajia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorted_arr(int *arr, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[j] < arr[i])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*fill_arr(t_stack *stack_a)
{
	int	len;
	int	*arr;
	int	i;

	len = stack_size(stack_a);
	arr = malloc(len * sizeof(int));
	i = 0;
	while (i < len)
	{
		arr[i] = stack_a->content;
		i++;
		stack_a = stack_a->next;
	}
	sorted_arr(arr, len);
	return (arr);
}

void	algo(t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;
	int	*arr;

	if (!stack_a || !*stack_a || !stack_b)
		return ;
	len_a = stack_size(*stack_a);
	if (len_a <= 1)
		return ;
	arr = fill_arr(*stack_a);
	if (arr == NULL)
	{
		stack_size(*stack_a);
		write(2, "Error\n", 6);
		exit(1);
	}
	push_to_b(stack_a, stack_b, arr, len_a);
	free(arr);
	push_to_a(stack_a, stack_b);
}

int	max_ind(t_stack **stack_b)
{
	t_stack	*go;
	int		max;
	int		position_of_max;
	int		position;

	go = *stack_b;
	position = 0;
	max = go->content;
	position_of_max = 0;
	while (go != NULL)
	{
		if (go->content > max)
		{
			max = go->content;
			position_of_max = position;
		}
		go = go->next;
		position++;
	}
	return (position_of_max);
}
