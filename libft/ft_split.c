/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zichajia <zichajia@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-27 09:27:32 by zichajia          #+#    #+#             */
/*   Updated: 2025-10-27 09:27:32 by zichajia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countw(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*wordcpy_and_len(char const *str, char c, int *len)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	*len = i;
	word = (char *)malloc((i + 1) * sizeof(char));
	if (!word)
		return (NULL);
	ft_memmove(word, str, i);
	word[i] = '\0';
	return (word);
}

static void	free_split(char **ars)
{
	int	i;

	i = 0;
	if (!ars)
		return ;
	while (ars[i])
	{
		free(ars[i]);
		i++;
	}
	free(ars);
}

static int	ft_processing(char **ars, char const *s, char c)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] && s[j] == c)
			j++;
		if (s[j])
		{
			len = 0;
			ars[i] = wordcpy_and_len(&s[j], c, &len);
			if (!ars[i])
			{
				free_split(ars);
				return (0);
			}
			i++;
			j += len;
		}
	}
	ars[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		count;

	if (!s)
		return (NULL);
	count = countw(s, c);
	arr = (char **)malloc((count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	if (!ft_processing(arr, s, c))
		return (NULL);
	return (arr);
}
