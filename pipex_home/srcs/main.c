/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:04:53 by gsims             #+#    #+#             */
/*   Updated: 2024/01/04 18:55:31 by georgesims       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"


// Loads of mallocs to be checked here
static void	ft_init_pipex(t_data *d, char *argv[], char *envp[])
{
	int	count;

	parse_cmds(argv, d);
	d->bin_paths = bin_paths(d, envp);
	count = ft_count_array(d->bin_paths);
	d->cmd_paths1 = (char **)malloc(sizeof(char *) * (count + 1));
	d->cmd_paths2 = (char **)malloc(sizeof(char *) * (count + 1));
	if (!d->cmd_paths1 || !d->cmd_paths2)
		exit(1);
	d->cmd_paths1 = combine_cmd_path(d, d->cmd1);
	d->cmd_paths2 = combine_cmd_path(d, d->cmd2);
	if (!d->cmd_paths1 || !d->cmd_paths2)
		exit(1);
}

static void	ft_open_files(t_data *d, char *argv[])
{
	d->file1 = open(argv[1], O_RDONLY);
	d->file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (d->file1 == -1 || d->file2 == -1)
	{
		perror("Error opening file(s)");
		ft_free_all(d);
		free(d->cmd_path1);
		free(d->cmd_path2);
		exit(1);
	}
}

static void	ft_exec(t_data *d, char *envp[])
{
	pid_t	pid;
	int		p;

	p = pipe(d->fd);
	if (p == -1)
	{
		perror("Error with pipe function");
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Error with fork function");
		exit(1);
	}
	if (pid == 0)
		child_process(d, envp);
	waitpid(-1, NULL, 0);
	parent_process(d, envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_data	*d;

	if (argc != 5)
		return (0);
	d = (t_data *)malloc(sizeof(t_data));
	if (!d)
		return (0);
	ft_init_pipex(d, argv, envp);
	if (path_access(d, &d->cmd_path1) == 0 || path_access2(d,
			&d->cmd_path2) == 0)
	{
		ft_free_all(d);
		exit(1);
	}
	ft_open_files(d, argv);
	ft_exec(d, envp);
	free(d->cmd_path1);
	free(d->cmd_path2);
	ft_free_all(d);
	return (0);
}
