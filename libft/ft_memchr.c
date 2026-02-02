/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zichajia <zichajia@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-21 10:43:10 by zichajia          #+#    #+#             */
/*   Updated: 2025-10-21 10:43:10 by zichajia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	to_find;

	to_find = (unsigned char)c;
	s = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (s[i] == to_find)
			return (&s[i]);
		i++;
	}
	return (NULL);
}
