/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:55:19 by georgesims        #+#    #+#             */
/*   Updated: 2024/01/04 18:55:23 by georgesims       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_process(t_data *d, char *envp[])
{
	close(d->fd[0]);
	dup2(d->fd[1], 1);
	dup2(d->file1, 0);
	close(d->fd[1]);
	if (execve(d->cmd_path1, d->cmd1, envp) == -1)
	{
		perror("execve");
		exit(1);
	}
}

void	parent_process(t_data *d, char *envp[])
{
	close(d->fd[1]);
	dup2(d->fd[0], 0);
	dup2(d->file2, 1);
	close(d->fd[0]);
	if (execve(d->cmd_path2, d->cmd2, envp) == -1)
	{
		perror("execve");
		exit(1);
	}
}