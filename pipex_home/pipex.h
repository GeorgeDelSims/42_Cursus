/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:43:38 by gsims             #+#    #+#             */
/*   Updated: 2023/12/14 09:15:11 by georgesims       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
#include <sys/types.h>

typedef struct  s_data
{
    int    file1;
    int    file2;
    int    fd[2];    
}            t_data;

void	child_process(t_data *data, char *argv[], char **env);
void	parent_process(t_data *data, char *argv[], char **env);
int 	main(int argc, char *argv[], char **env);


#endif

