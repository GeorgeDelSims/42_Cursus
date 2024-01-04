/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:27:01 by gsims             #+#    #+#             */
/*   Updated: 2024/01/04 17:20:41 by georgesims       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// Iterates through envp and returns the various paths as a single string
static char	*ft_parse_path(char *envp[])
{
	char	*path_from_env;
	int		index;

	index = 0;
	if (envp == NULL)
		return (NULL);
	while (envp[index] != NULL)
	{
		if (ft_strncmp(envp[index], "PATH=", 5) == 0)
			break ;
		index++;
	}
	path_from_env = ft_substr(envp[index], 5, ft_strlen(envp[index]));
	if (path_from_env == NULL)
	{
		free(path_from_env);
		return (NULL);
	}
	return (path_from_env);
}

// splits the path string into the various possible paths to binary files
char	**bin_paths(t_data *d, char *envp[])
{
	char	*path_from_env;

	path_from_env = ft_parse_path(envp);
	if (path_from_env == NULL)
		return (NULL);
	d->bin_paths = ft_split(path_from_env, ':');
	free(path_from_env);
	return (d->bin_paths);
}

// splits the command string into the various arguments
void	parse_cmds(char *argv[], t_data *d)
{
	int	count1;
	int	count2;

	d->cmd1 = ft_split(argv[2], ' ');
	d->cmd2 = ft_split(argv[3], ' ');
	count1 = ft_count_array(d->cmd1);
	count2 = ft_count_array(d->cmd2);
	d->cmd1[count1] = NULL;
	d->cmd2[count2] = NULL;
}

// Create array of paths with command appended
char	**combine_cmd_path(t_data *d, char *cmd[])
{
	int		i;
	char	**cmd_paths;

	cmd_paths = NULL;
	if (cmd == d->cmd1)
		cmd_paths = d->cmd_paths1;
	else if (cmd == d->cmd2)
		cmd_paths = d->cmd_paths2;
	i = 0;
	if (cmd_paths)
	{
		while (d->bin_paths[i])
		{
			cmd_paths[i] = ft_strjoin_mod(d->bin_paths[i], cmd[0]);
			i++;
		}
		cmd_paths[i] = NULL;
	}
	return (cmd_paths);
}
