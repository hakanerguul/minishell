/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opiltan <opiltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 02:11:36 by opiltan           #+#    #+#             */
/*   Updated: 2023/01/31 05:04:40 by opiltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

/*It changes the current working directory to the one specified by the user*/
void	change_path(t_tools *tools)
{
	char	*tmp;

	tmp = ft_strdup(tools->pwd);
	free(tools->old_pwd);
	tools->old_pwd = tmp;
	free(tools->pwd);
	tools->pwd = getcwd(NULL, sizeof(NULL));
}

/*It returns the index of the first equal sign in a string*/
size_t	equal_sign(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (i + 1);
		i++;
	}
	return (0);
}

/*It deletes the quotes from a string*/
char	*delete_quotes_value(char *str)
{
	char	**split_quotes;

	split_quotes = ft_split(str, '"');
	if (!split_quotes[1])
	{
		free_arr(split_quotes);
		split_quotes = ft_split(str, '\'');
	}
	free(str);
	str = ft_strjoin(split_quotes[0], split_quotes[1]);
	free_arr(split_quotes);
	return (str);
}

int	check_valid_identifier(char c)
{
	return (c == '|' || c == '<' || c == '>' || c == '[' || c == ']'
		|| c == '\'' || c == '\"' || c == ' ' || c == ',' || c == '.'
		|| c == ':' || c == '/' || c == '{' || c == '}' || c == '+'
		|| c == '^' || c == '%' || c == '#' || c == '@' || c == '!'
		|| c == '~'
		|| c == '=' || c == '-' || c == '?' || c == '&' || c == '*');
}

// "\'\"\\$ ,.:/[{]}+=-?&*^%#@!~"