/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:41:46 by gsims             #+#    #+#             */
/*   Updated: 2024/02/08 09:53:13 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// Test if these paths can be accessed and execve if they can
int	path_access(t_data *d, char **cmd_path)
{
	int	i;

	i = 0;
	while (d->cmd_paths1[i])
	{
		if (access(d->cmd_paths1[i], X_OK) == 0)
		{
			*cmd_path = ft_strdup(d->cmd_paths1[i]);
			return (1);
		}
		i++;
	}
	perror("pipex: cmd1: command not found: ");
	return (0);
}

// Test if these paths can be accessed and execve if they can
int	path_access2(t_data *d, char **cmd_path)
{
	int	i;

	i = 0;
	while (d->cmd_paths2[i])
	{
		if (access(d->cmd_paths2[i], X_OK) == 0)
		{
			*cmd_path = ft_strdup(d->cmd_paths2[i]);
			return (1);
		}
		i++;
	}
	perror("pipex: cmd2: command not found: ");
	return (0);
}
