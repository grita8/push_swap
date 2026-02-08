/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zichajia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:01:58 by zichajia          #+#    #+#             */
/*   Updated: 2026/02/08 14:02:05 by zichajia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_lst_size(t_stack **list, char **two_d, char *args)
{
	if (stack_size(*list) == 1)
	{
		free_stack(*list);
		ftt_free(two_d);
		free(args);
		exit(1);
	}
}

void	check(t_stack **a, char **two_d, char *args)
{
	is_lst_size(a, two_d, args);
	check_is_duplicated(is_duplicated(*a), a, two_d, args);
	check_is_sorted(sorted(a), a, two_d, args);
}
