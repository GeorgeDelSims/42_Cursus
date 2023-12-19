/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:27:01 by gsims             #+#    #+#             */
/*   Updated: 2023/12/19 15:52:49 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// Iterates through envp and returns the various paths as a single string
static char *ft_parse_path(char *envp[])
{
	char	*path_from_env;
	int		index;
	
	index = 0;
	while (envp[index] != NULL)
	{
		if (ft_strncmp(envp[index], "PATH=", 5) == 0)
			break ;
		index++;
	}
	path_from_env = ft_substr(envp[index], 5, ft_strlen(envp[index])); // Malloc !!!
	if (path_from_env == NULL)
	{
		free(path_from_env);
		return (NULL);
	}
	return (path_from_env);
}

// splits the path string into the various possible paths to binary files
char **bin_paths(t_data *d)
{
	char	*path_from_env;
	
	path_from_env = ft_parse_path(d->env);
	if (path_from_env == NULL)
		return (NULL);
	d->bin_paths = ft_split(path_from_env, ':');
	free(path_from_env); // ft_substr freed here !!
	return (d->bin_paths);
}

// splits the command string into the various arguments
void	parse_cmds(char *argv[], t_data *d)
{
	d->cmd1 = ft_split(argv[2], ' '); // Malloc !!!
	d->cmd2 = ft_split(argv[3], ' '); // Malloc !!!
}

// Create array of paths with command appended
char	**combine_cmd_path(t_data *d, char *cmd[])
{
	int		i;
	
	i = 0;
	while (d->bin_paths[i])
	{
		if (cmd == d->cmd1)
		{
			d->cmd_paths1[i] = NULL;
			d->cmd_paths1[i] = ft_strjoin_mod(d->bin_paths[i], cmd[0]);
		}
		else if (cmd == d->cmd2)
			d->cmd_paths2[i] = NULL;
			d->cmd_paths2[i] = ft_strjoin_mod(d->bin_paths[i], cmd[0]);
		i++;
	}
	if (cmd == d->cmd1)
	{
		d->cmd_paths1[i] = NULL;
		return (d->cmd_paths1);
	}	
	else if (cmd == d->cmd2)
	{
		d->cmd_paths2[i] = NULL;
		return (d->cmd_paths2);
	}
	else
		return (NULL);
}
