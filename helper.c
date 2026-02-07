#include "push_swap.h"

char	*ft_sstrjoin(char *save, char *buff)
{
	size_t	i;
	size_t	j;
	int		len;
	char	*str;

	i = 0;
	j = 0;
	if (!save && !buff)
		return (NULL);
	if (!save && buff)
		return (ft_strdup(buff));
	if (save && !buff)
		return (ft_strdup(save));
	len = ft_strlen(save) + ft_strlen(buff);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
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

void	initialise(t_state *state, char *args)
{
	state->i = 0;
	state->end = 0;
	state->k = 0;
	state->tow_d = 0;
	state->start = 0;
	state->cw = count_word(args);
	state->tow_d = (char **)malloc((state->cw + 1) * sizeof(char *));
}

char	**split_args(char *args)
{
	t_state	state;

	initialise(&state, args);
	while (args[state.i])
	{
		while (args[state.i] && args[state.i] == ' ')
			state.i++;
		state.start = state.i;
		while (args[state.i] && args[state.i] != ' ')
			state.i++;
		state.end = state.i;
		if (state.start < state.end)
		{
			state.tow_d[state.k] = ft_strcopy(args, state.start, state.end);
			if (!state.tow_d[state.k])
				ftt_free(state.tow_d);
			state.k++;
		}
	}
	state.tow_d[state.k] = NULL;
	return (state.tow_d);
}
