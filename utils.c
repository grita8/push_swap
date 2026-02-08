/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zichajia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:07:02 by zichajia          #+#    #+#             */
/*   Updated: 2026/02/08 14:07:05 by zichajia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strcopy(char *str, int start, int end)
{
	int		i;
	char	*s;

	i = 0;
	s = malloc((end - start + 1));
	if (!s)
		return (NULL);
	while (start < end)
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
			i++;
		if (args[i] && args[i] != ' ')
			cw++;
		while (args[i] && args[i] != ' ')
			i++;
	}
	return (cw);
}

t_stack	*new_node(int content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	add_back(t_stack **head, int content)
{
	t_stack	*node;
	t_stack	*current;

	node = new_node(content);
	if (*head == NULL)
	{
		*head = node;
		return ;
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = node;
}
