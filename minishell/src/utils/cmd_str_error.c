/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_str_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opiltan <opiltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:15:10 by opiltan           #+#    #+#             */
/*   Updated: 2023/01/31 06:34:20 by opiltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	str_control(t_tools *tools)
{
	t_simple_cmds	*cmds;
	int				i;
	int				j;

	j = 0;
	i = 0;
	cmds = tools->simple_cmds;
	while (cmds)
	{
		while (cmds->str[i])
		{
			while (cmds->str[i][j])
			{
				if (ft_isprint(cmds->str[i][j]))
					return (0);
				j++;
			}
			i++;
		}
		i = 0;
		cmds = cmds->next;
	}
	return (1);
}

static void	delete_quotes2(char *str, int *i, int *j, char *temp)
{
	if (str[*i] == '\"' || (str[*i] == '\"' && str[*i + 1] == ' '))
	{
		(*i)++;
		while (str[*i] != '\"')
			temp[(*j)++] = str[(*i)++];
		(*i)++;
	}
	else if (str[*i] == '\'')
	{
		(*i)++;
		while (str[*i] != '\'')
			temp[(*j)++] = str[(*i)++];
		(*i)++;
	}
}

char	*delete_quotes(char *str)
{
	int		i;
	int		j;
	char	*temp;

	j = 0;
	i = 0;
	temp = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			delete_quotes2(str, &i, &j, temp);
		}
		else
			temp[j++] = str[i++];
	}
	temp[j] = '\0';
	free(str);
	return (temp);
}
