/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zichajia <zichajia@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-18 09:11:30 by zichajia          #+#    #+#             */
/*   Updated: 2025-10-18 09:11:30 by zichajia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n > 0)
	{
		*p++ = (unsigned char)c;
		n--;
	}
	return (s);
}

// #include <string.h>

// int main()
// {
// 	int a = 0;
// 	unsigned char *p = (unsigned char *)&a;
// 	ft_memset(p, 199, 1);
// 	ft_memset(p+1, 5, 1);
// 	ft_memset(p+2, 0, 1);
// 	ft_memset(p+3, 0, 1);
// 	printf("%d\n", a);
// }
