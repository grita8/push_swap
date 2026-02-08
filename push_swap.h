/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zichajia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:03:19 by zichajia          #+#    #+#             */
/*   Updated: 2026/02/08 14:03:26 by zichajia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct stack_list
{
	int					content;
	struct stack_list	*next;
}						t_stack;

typedef struct s_atoa_state
{
	int					i;
	long				result;
	int					signe;
	int					tmp;
}						t_atoa_state;

typedef struct s_state
{
	int		i;
	int		start;
	int		k;
	int		cw;
	int		end;
	char	**tow_d;
}			t_state;

int		*fill_arr(t_stack *stack_a);
void	sorted_arr(int *arr, int len);
int		put_chunk(int len_a);
void	increment(int *i, int *chunk, int len);
void	push_to_b(t_stack **stack_a, t_stack **stack_b, int *arr, int len_a);
void	algo(t_stack **stack_a, t_stack **stack_b);
void	push_to_a(t_stack **stack_a, t_stack **stack_b);
int		is_it_alpha(char *str, int *i);
void	check_int_overflow(long number, t_stack *list,
			char **two_d, char *args);
void	init_vars(t_atoa_state *vars);
int		ff_atoi(char *str, t_stack *list, char **two_d, char *args);
void	else_of_atoi(t_stack **list, char **two_d, char *args);
char	*join_args(int argc, char **argv);
char	*ft_sstrjoin(char *save, char *buff);
char	*ftt_free(char **arr);
void	initialise(t_state *state, char *args);
char	*ft_strcopy(char *str, int start, int end);
char	**split_args(char *args);
int		count_word(char *args);
void	create_stack_a(char **two_d, t_stack **list, char *args);
int		stack_size(t_stack *stack);
void	check_is_sorted(int value, t_stack **list, char **two_d, char *args);
void	check_is_duplicated(int value, t_stack **list,
			char **two_d, char *args);
void	is_lst_size(t_stack **list, char **two_d, char *args);
int		is_duplicated(t_stack *list);
void	check(t_stack **a, char **two_d, char *args);
void	is_it_null(char **argv, int argc);
t_stack	*new_node(int content);
void	add_back(t_stack **stack, int content);
void	free_stack(t_stack *stack);
int		swap_stack_b(t_stack **stack_b);
int		swap_stack_a(t_stack **stack_a);
void	ft_putstr(char *str);

void	push_min_to_b(t_stack **stack_a, t_stack **stack_b);
int		min_position(t_stack **stack);
int		max_position(t_stack **stack_a);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);
void	sort2(t_stack **stack_a);
void	sort3(t_stack **stack_a);
void	sort4(t_stack **stack_a, t_stack **stack_b);
void	sort5(t_stack **stack_a, t_stack **stack_b);
int		sorted(t_stack **stack_a);

int		sa(t_stack **stack_b);
int		sb(t_stack **stack_b);
int		ss(t_stack **stack_a, t_stack **stack_b, int index);

int		push_a(t_stack **stack_a, t_stack **stack_b);
int		push_b(t_stack **stack_a, t_stack **stack_b);

int		pb(t_stack **stack_a, t_stack **stack_b);
int		pa(t_stack **stack_a, t_stack **stack_b);

int		rotate_stack_a(t_stack **stack_b);
int		rotate_stack_b(t_stack **stack_b);

int		ra(t_stack **stack_a);
int		rb(t_stack **stack_a);
int		rr(t_stack **stack_a, t_stack **stack_b, int index);

int		reverse_rotate_stack_a(t_stack **stack_a);
int		reverse_rotate_stack_b(t_stack **stack_b);

int		rra(t_stack **stack_a);
int		rrb(t_stack **stack_a);
int		rrr(t_stack **stack_a, t_stack **stack_b, int index);

#endif
