/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:41:46 by gsims             #+#    #+#             */
/*   Updated: 2024/01/04 18:56:49 by georgesims       ###   ########.fr       */
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
			*cmd_path = ft_strdup(d->cmd_paths1[i]); // Malloc !!!
			return (1);
		}
		i++;
	}
	perror("\033[31mpath invalid or cannot be accessed.");
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
	ft_printf("\033[31mpath invalid or cannot be accessed.\n");
	return (0);
}
