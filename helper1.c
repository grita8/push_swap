/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zichajia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:19:28 by zichajia          #+#    #+#             */
/*   Updated: 2026/02/08 14:19:33 by zichajia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ftt_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

void	create_stack_a(char **two_d, t_stack **list, char *args)
{
	int	i;

	i = 0;
	while (two_d[i])
	{
		add_back(list, ff_atoi(two_d[i], *list, two_d, args));
		i++;
	}
}

void	initialise(t_state *state, char *args)
{
	state->i = 0;
	state->end = 0;
	state->k = 0;
	state->tow_d = 0;
	state->start = 0;
	state->cw = count_word(args);
	state->tow_d = (char **)malloc((state->cw + 1) * sizeof(char *));
}

char	**split_args(char *args)
{
	t_state	state;

	initialise(&state, args);
	while (args[state.i])
	{
		while (args[state.i] && args[state.i] == ' ')
			state.i++;
		state.start = state.i;
		while (args[state.i] && args[state.i] != ' ')
			state.i++;
		state.end = state.i;
		if (state.start < state.end)
		{
			state.tow_d[state.k] = ft_strcopy(args, state.start, state.end);
			if (!state.tow_d[state.k])
				ftt_free(state.tow_d);
			state.k++;
		}
	}
	state.tow_d[state.k] = NULL;
	return (state.tow_d);
}
