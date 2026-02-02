#include "push_swap.h"

#include <stdio.h>
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

void ft_putstr(char *str)
{
    while(*str)
    {
        write(1, str, 1);
        str++;
    }
}

void free_stack(list_t *stack)
{
    list_t *tmp;

    while (stack)
    {
        tmp = stack->next;
        free(stack);
        stack = tmp;
    }
}

list_t *new_node(int content)
{
    list_t *node = malloc(sizeof(list_t));
    if (!node)
        return NULL;
    node->content = content;
    node->next = NULL;
    return node;
}

void add_back(list_t **stack, list_t *new)
{
    list_t *tmp;

     if (!stack || !new)
        return;
    
    if (!*stack)
    {
        *stack = new;
        return;
    }
    tmp = *stack;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}

list_t *creat_stack(int argc, char **argv)
{
    list_t *stack = NULL;
    int i = 1;

    while (i < argc)
    {
        add_back(&stack, new_node(ft_atoi(argv[i])));
        i++;
    }
    return stack;
}

list_t *creat_stack_from_split(char **tow_d)
{
    list_t *stack = NULL;
    int i = 0;

    while (tow_d[i])
    {
        add_back(&stack, new_node(ft_atoi(tow_d[i])));
        i++;
    }
    return stack;
}

void ft_putnbr(int nb)
{
    char c;
    if (nb < 0)
    {
        nb = -nb;
        write(1, "-", 1);
    }
    if (nb >= 10)
    {
        ft_putnbr(nb / 10);
    }
    c = (nb % 10) + '0';
    write(1, &c, 1);
}

void print_stack(list_t *stack)
{
    while (stack)
    {
        ft_putnbr(stack->content);
        write(1, " ", 1);
        stack = stack->next;
    }
    write(1, "\n", 1);
}

int stack_size(list_t *stack)
{
    int size = 0;

    while (stack)
    {
        size++;
        stack = stack->next;
    }
    return size;
}

void sort_stack(list_t **stack_a, list_t **stack_b)
{
    int size;

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

int main(int argc, char **argv)
{
    char			*args;
	char			**strs;
    list_t *stack_a = NULL;
    list_t *stack_b = NULL;

    if (argc < 2)
        return 1;

    is_it_null(argv, argc);
	is_it_space(argv);

    stack_a = creat_stack(argc, argv);

    args = join_args(argc, argv);
    printf("Joined: '%s'\n", args);
    strs = split_args(args);
    stack_a = creat_stack_from_split(strs);
    printf("split: '%s'\n", args);

    sort_stack(&stack_a, &stack_b);
    print_stack(stack_a);
    
    ftt_free(strs); 
    free_stack(stack_a);
    return 0;
}
