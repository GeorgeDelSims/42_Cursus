/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:04:53 by gsims             #+#    #+#             */
/*   Updated: 2023/12/21 16:29:44 by georgesims       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Main Function takes all four args as input 
// arg[1] and arg[4] are file names
// arg[2] and arg[3] are shell commands.
// the result of cmd1 being applied to file1 needs to be fed to cmd2 and applied to file2.

#include "../includes/pipex.h"

void	child_process(t_data *d, char *envp[])
{
	// close the read end of the pipe
	close(d->fd[0]);
	// make the standard output (stdout = 1) of the current process
	// into a copy of the write end of the pipe (fd[1])
	dup2(d->fd[1], 1);
	// close the write end of the pipe
	close(d->fd[1]);
	// execute the first command
	execve(d->cmd_path1, d->cmd1, envp);
}

void	parent_process(t_data *d, char *envp[])
{
	int		status;
	
	waitpid(-1, &status, 0);
	// close the write end of the pipe
	close(d->fd[1]);
	// make the standard input (stdin = 0) of the current process
	// into a copy of the read end of the pipe (fd[0])
	dup2(d->fd[0], 0);
	// close the read end of the pipe
	close(d->fd[0]);
	// execute the second command
	execve(d->cmd_path2, d->cmd2, envp);
}

// Loads of mallocs to be checked here
static int	ft_init_pipex(t_data *d, char *argv[], char *envp[])
{	
	parse_cmds(argv, d);
	d->bin_paths = bin_paths(d, envp);
	d->cmd_paths1 = (char **)malloc(sizeof(char *));
	d->cmd_paths2 = (char **)malloc(sizeof(char *));
	if	(!d->cmd_paths1 || !d->cmd_paths2)
		return (0);
	d->cmd_paths1 = combine_cmd_path(d, d->cmd1);
	d->cmd_paths2 = combine_cmd_path(d, d->cmd2);
	if	(!d->cmd_paths1 || !d->cmd_paths2)
		return (0);
	return (1);
}

static int	ft_open_files(t_data *d, char *argv[])
{
	d->file1 = open(argv[1], O_RDONLY);
	d->file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (d->file1 == -1 || d->file2 == -1)
	{
		perror("Error");
		exit(1);
	}
	return (1);
}

static void	ft_exec(t_data *d, char *envp[])
{
	pid_t	pid;
	
	pipe(d->fd); // fd[0] = read end ; fd[1] = write end 
	if (pipe(d->fd) == -1)
	{
		perror("Error");
		exit(1);
	}
	// fork() creates a child process
	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		exit(1);
	}
	// child process
	if (pid == 0)
		child_process(d, envp);
	// parent process	
	else
		parent_process(d, envp);
}

// static void	ft_print_array(char **array)
// {
// 	int	i;

// 	i = 0;
// 	while (array[i])
// 	{
// 		ft_printf("%s\n", array[i]);
// 		i++;
// 	}
// }


int	main(int argc, char *argv[], char *envp[])
{
	
	t_data	*d;
	
	if (argc != 5)
		return (0);
	d = (t_data *)malloc(sizeof(t_data));
	if (!d)
		return (0);
	if (ft_init_pipex(d, argv, envp) == 0)
		return (0);
	// ft_print_array(d->cmd_paths1);
	ft_printf("Made it to here\n");
	ft_printf("d->cmd_paths1[0] : %s\n", d->cmd_paths1[0]);
	ft_printf("d->cmd_paths1[1] : %s\n", d->cmd_paths1[1]);
	// ft_print_array(d->cmd_paths2);
	if (path_access(d, &d->cmd_path1) == 0 || path_access2(d, &d->cmd_path2) == 0)
	{
		//free all used variables
		return (0);
	}
	// open file1 for reading and file2 for writing
	if (ft_open_files(d, argv) == 0)
		return (0);
	// pipe reads from fd[0] and writes to fd[1]
	ft_exec(d, envp);
	return (0);
}