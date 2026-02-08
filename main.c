/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zichajia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:01:22 by zichajia          #+#    #+#             */
/*   Updated: 2026/02/08 14:01:25 by zichajia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_it_space(char **str)
{
	int	i;
	int	len;
	int	check;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		check = 0;
		len = ft_strlen(str[i]);
		while (str[i][j])
		{
			if (str[i][j] == ' ')
				check++;
			j++;
		}
		if (check == len)
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

void	is_it_null(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!argv[i][0])
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*args;
	char	**strs;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (1);
	is_it_null(argv, argc);
	is_it_space(argv);
	args = join_args(argc, argv);
	strs = split_args(args);
	create_stack_a(strs, &stack_a, args);
	check(&stack_a, strs, args);
	if (stack_size(stack_a) <= 5)
		sort_stack(&stack_a, &stack_b);
	else
		algo(&stack_a, &stack_b);
	ftt_free(strs);
	free_stack(stack_a);
	free(args);
	return (0);
}
