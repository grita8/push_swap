#include "push_swap.h"

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

char *ft_strcopy(char *str, int start, int end)
{
    int i = 0;
    char *s = malloc((end - start + 1));
    if(!s)
    return NULL;
    while(start < end)
    {
        s[i] = str[start];
        start++;
        i++;
    }
    s[i] = '\0';
    return (s);
}

int	count_word(char *args)
{
	int	i;
	int	cw;

	i = 0;
	cw = 0;
	while (args[i])
	{
		while (args[i] && args[i] == ' ')
		{
			i++;
		}
		if (args[i] && args[i] != ' ')
		{
			cw++;
		}
		while (args[i] && args[i] != ' ')
		{
			i++;
		}
	}
	return (cw);
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