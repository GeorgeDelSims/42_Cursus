/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:55:19 by georgesims        #+#    #+#             */
/*   Updated: 2024/01/09 13:23:04 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_process(t_data *d, char *envp[])
{
	close(d->fd[0]);
	dup2(d->fd[1], 1);
	dup2(d->infile, 0);
	close(d->fd[1]);
	if (execve(d->cmd_path1, d->cmd1, envp) == -1)
	{
		perror("execve failed");
		exit(EXIT_FAILURE);
	}
}

void	parent_process(t_data *d, char *envp[])
{
	close(d->fd[1]);
	dup2(d->fd[0], 0);
	dup2(d->outfile, 1);
	close(d->fd[0]);
	if (execve(d->cmd_path2, d->cmd2, envp) == -1)
	{
		perror("execve failed");
		exit(EXIT_FAILURE);
	}
}
