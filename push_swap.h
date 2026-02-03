#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft.h"
#include <stdlib.h>
# include <limits.h>
#include <unistd.h>


typedef struct stack_list
{
    int             content;
    struct stack_list   *next;
} list_t;

typedef struct s_state
{
    int i;
    int start;
    int k;
    int cw;
    int end;
    char **tow_d;
}       t_state; 

typedef struct s_atoa_state
{
	int					i;
	long				result;
	int					signe;
	int					tmp;
}						t_atoa_state;

int	is_it_alpha(char *str, int *i);
void	check_int_overflow(long number, list_t *list, char **two_d,
		char *args);
void	init_vars(t_atoa_state *vars);
int	ff_atoi(char *str, list_t *list, char **two_d, char *args);
void	else_of_atoi(list_t **list, char **two_d, char *args);


char	*join_args(int argc, char **argv);
char *ft_sstrjoin(char *save, char *buff);
char	*ftt_free(char **arr);
void initialise(t_state *state, char *args);
char *ft_strcopy(char *str, int start, int end);
char **split_args(char *args);
int	count_word(char *args);
list_t *creat_stack_from_split(char **two_d, list_t *list, char **all_args, char *joined_args);

int stack_size(list_t *stack);
void	check_is_sorted(int value, list_t **list, char **two_d,
		char *args);
void	check_is_duplicated(int value, list_t **list, char **two_d,
		char *args);
void	is_lst_size(list_t **list, char **two_d, char *args);
int	is_duplicated(list_t *list);
void	check(list_t **a, char **two_d, char *args);


void	is_it_null(char **argv, int argc);
list_t  *new_node(int content);
void    add_back(list_t **stack, list_t *new);
list_t  *creat_stack(int argc, char **argv);
void    ft_putnbr(int nb);
void    free_stack(list_t *stack);

int	swap_stack_b(list_t **stack_b);
int	swap_stack_a(list_t **stack_a);
void ft_putstr(char *str);


void push_min_to_b(list_t **stack_a, list_t **stack_b);
int min_position(list_t **stack);
int max_position(list_t **stack_a);
int stack_size(list_t *stack);
void sort_stack(list_t **stack_a, list_t **stack_b);
void sort2(list_t **stack_a);
void sort3(list_t **stack_a);
void sort4(list_t **stack_a, list_t **stack_b);
void sort5(list_t **stack_a, list_t **stack_b);
int sorted(list_t **stack_a);

int	sa(list_t **stack_b);
int	sb(list_t **stack_b);
int ss(list_t **stack_a, list_t **stack_b, int index);

int push_a(list_t **stack_a, list_t **stack_b);
int push_b(list_t **stack_a, list_t **stack_b);

int pb(list_t **stack_a, list_t **stack_b);
int pa(list_t **stack_a, list_t **stack_b);

int rotate_stack_a(list_t **stack_b);
int rotate_stack_b(list_t **stack_b);

int	ra(list_t **stack_a);
int	rb(list_t **stack_a);
int rr(list_t **stack_a, list_t **stack_b, int index);

int reverse_rotate_stack_a(list_t **stack_a);
int reverse_rotate_stack_b(list_t **stack_b);

int	rra(list_t **stack_a);
int	rrb(list_t **stack_a);
int rrr(list_t **stack_a, list_t **stack_b, int index);

// int	is_sorted(list_t *list);
#endif
