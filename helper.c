/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zichajia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:18:21 by zichajia          #+#    #+#             */
/*   Updated: 2026/02/08 14:18:48 by zichajia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*handle_null_cases(char *save, char *buff)
{
	if (!save && !buff)
		return (NULL);
	if (!save && buff)
		return (ft_strdup(buff));
	if (save && !buff)
		return (ft_strdup(save));
	return (NULL);
}

static void	copy_strings(char *str, char *save, char *buff)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (save[i])
	{
		str[i] = save[i];
		i++;
	}
	while (buff[j])
	{
		str[i + j] = buff[j];
		j++;
	}
	str[i + j] = '\0';
}

char	*ft_sstrjoin(char *save, char *buff)
{
	int		len;
	char	*str;
	char	*result;

	result = handle_null_cases(save, buff);
	if (!save || !buff)
		return (result);
	len = ft_strlen(save) + ft_strlen(buff);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	copy_strings(str, save, buff);
	free(save);
	return (str);
}

char	*join_args(int argc, char **argv)
{
	int		i;
	char	*args;

	i = 1;
	args = NULL;
	while (i < argc)
	{
		args = ft_sstrjoin(args, argv[i]);
		if (i != argc - 1)
			args = ft_sstrjoin(args, " ");
		i++;
	}
	return (args);
}
