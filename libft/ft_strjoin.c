/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zichajia <zichajia@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-21 17:00:18 by zichajia          #+#    #+#             */
/*   Updated: 2025-10-21 17:00:18 by zichajia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	len;

	len = ft_strlen_(s1) + ft_strlen_(s2);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	len = 0;
	i = 0;
	while (s1 && s1[i])
	{
		res[len++] = s1[i++];
	}
	i = 0;
	while (s2 && s2[i])
	{
		res[len++] = s2[i++];
	}
	res[len] = '\0';
	return (res);
}
