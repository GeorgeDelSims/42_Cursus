/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:04:53 by gsims             #+#    #+#             */
/*   Updated: 2023/12/13 08:41:07 by georgesims       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// Main Function takes all four args as input 
// arg[1] and arg[4] are file names
// arg[2] and arg[3] are shell commands.
// the result of cmd1 being applied to file1 needs to be fed to cmd2 and applied to file2.

#include "pipex.h"

int	main(int argc, char *argv[])
{
	int		file1;
	int		file2;
	int		fd[2];
	pid_t	pid;
	
	if (argc != 5)
		return (0);
	// open file1 for reading and file2 for writing
	file1 = open(argv[1], O_RDONLY);
	file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file1 == -1 || file2 == -1)
	{
		perror("Error");
		exit(1);
	}
	// pipe reads from fd[0] and writes to fd[1]
	pipe(fd);
	if (pipe(fd) == -1)
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
	{
		// close the read end of the pipe
		close(fd[0]);
		// make the standard output (stdout = 1) of the current process
		// into a copy of the write end of the pipe (fd[1])
		dup2(fd[1], 1);
		// close the write end of the pipe
		close(fd[1]);
		// execute the first command
		execve(argv[2], argv[2], NULL);
	}
	// parent process
	else
	{
		// close the write end of the pipe
		close(fd[1]);
		// make the standard input (stdin = 0) of the current process
		// into a copy of the read end of the pipe (fd[0])
		dup2(fd[0], 0);
		// close the read end of the pipe
		close(fd[0]);
		// execute the second command
		execve(argv[3], argv[3], NULL);
	}
}
