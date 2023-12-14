/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:04:53 by gsims             #+#    #+#             */
/*   Updated: 2023/12/14 18:13:58 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Main Function takes all four args as input 
// arg[1] and arg[4] are file names
// arg[2] and arg[3] are shell commands.
// the result of cmd1 being applied to file1 needs to be fed to cmd2 and applied to file2.

#include "../includes/pipex.h"

void	child_process(t_data *data)
{
	// close the read end of the pipe
	close(data->fd[0]);
	// make the standard output (stdout = 1) of the current process
	// into a copy of the write end of the pipe (fd[1])
	dup2(data->fd[1], 1);
	// close the write end of the pipe
	close(data->fd[1]);
	// execute the first command
	execve(data->cmd_path1, data->cmd1, data->env);
}

void	parent_process(t_data *data)
{
	int		status;
	
	waitpid(-1, &status, 0);
	// close the write end of the pipe
	close(data->fd[1]);
	// make the standard input (stdin = 0) of the current process
	// into a copy of the read end of the pipe (fd[0])
	dup2(data->fd[0], 0);
	// close the read end of the pipe
	close(data->fd[0]);
	// execute the second command
	execve(data->cmd_path2, data->cmd2, data->env);
}

// Combine all string parsing functions into one main one
static void	str_parsing(char *argv[], t_data *data)
{
	parse_cmds(argv, data);
	data->bin_paths = bin_paths(data);
	data->cmd_paths1 = combine_cmd_path(data, data->cmd1);
	data->cmd_paths2 = combine_cmd_path(data, data->cmd2);
}

// Example: ./pipex file1 ls -a wc file2 
// ==> 

int	main(int argc, char *argv[], char *envp[])
{
	pid_t	pid;
	t_data	*data;
	
	if (argc != 5)
		return (0);
	// initialise some struct variables 
	data = (char *)malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->env = envp;
	str_parsing(argv, data);
	if (path_access(data, data->cmd_path1) == 0 || path_access(data, data->cmd_path2) == 0)
	{
		//free all used variables
		return (0);
	}
	// open file1 for reading and file2 for writing
	data->file1 = open(argv[1], O_RDONLY);
	data->file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->file1 == -1 || data->file2 == -1)
	{
		perror("Error");
		exit(1);
	}
	// pipe reads from fd[0] and writes to fd[1]
	pipe(data->fd);
	if (pipe(data->fd) == -1)
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
		child_process(data);
	// parent process	
	else
		parent_process(data);
	return (0);
}
