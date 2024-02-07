/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:04:53 by gsims             #+#    #+#             */
/*   Updated: 2024/02/07 12:22:20 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// ./pipex file1.txt cat tee file2.txt
// Bash : cat file1.txt | tee file2.txt
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
		exit(EXIT_FAILURE);
	d->cmd_paths1 = combine_cmd_path(d, d->cmd1);
	d->cmd_paths2 = combine_cmd_path(d, d->cmd2);
	if (!d->cmd_paths1 || !d->cmd_paths2)
		exit(EXIT_FAILURE);
}

static void	ft_open_files(t_data *d, char *argv[])
{
	ft_printf("Opening infile: %s\n", argv[1]);
	d->infile = open(argv[1], O_RDONLY);
	ft_printf("Opening outfile: %s\n", argv[4]);
	d->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (d->infile == -1 || d->outfile == -1)
	{
		perror("Could not open data file(s)");
		ft_free_all(d);
		free(d->cmd_path1);
		free(d->cmd_path2);
		exit(EXIT_FAILURE);
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
		exit(EXIT_FAILURE);
	d = (t_data *)malloc(sizeof(t_data));
	if (!d)
		exit(EXIT_FAILURE);
	ft_init_pipex(d, argv, envp);
	if (path_access(d, &d->cmd_path1) == 0 || path_access2(d,
			&d->cmd_path2) == 0)
	{
		ft_free_all(d);
		exit(127);
	}
	ft_open_files(d, argv);
	ft_exec(d, envp);
	free(d->cmd_path1);
	free(d->cmd_path2);
	ft_free_all(d);
	return (EXIT_SUCCESS);
}
