/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opiltan <opiltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 04:48:53 by opiltan           #+#    #+#             */
/*   Updated: 2023/01/31 05:02:32 by opiltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	mini_env(t_tools *tools, t_simple_cmds *simple_cmd)
{
	int		i;

	i = 0;
	while (tools->envp[i])
	{
		if (!ft_strncmp(simple_cmd->str[0], "export", \
			ft_strlen(simple_cmd->str[0])))
			ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putendl_fd(tools->envp[i], STDOUT_FILENO);
		i++;
	}
	return (EXIT_SUCCESS);
}
