/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zichajia <zichajia@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-18 09:11:19 by zichajia          #+#    #+#             */
/*   Updated: 2025-10-18 09:11:19 by zichajia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	destlen;
	size_t	srclen;
	size_t	i;

	srclen = ft_strlen(src);
	if (!dest && size == 0)
		return (srclen);
	destlen = ft_strlen(dest);
	if (size <= destlen)
		return (size + srclen);
	i = 0;
	while (src[i] && destlen + i < size - 1)
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	return (destlen + srclen);
}
