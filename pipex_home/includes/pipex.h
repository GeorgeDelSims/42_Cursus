/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:43:38 by gsims             #+#    #+#             */
/*   Updated: 2023/12/19 15:56:44 by gsims            ###   ########.fr       */
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
# include <sys/types.h>
# include "../libft/libft.h"

typedef struct  s_data
{
    int     file1;
    int     file2;
    int     fd[2];
    char    **bin_paths; // needs to be freed
    char    **cmd_paths1; // needs to be freed
    char    **cmd_paths2; // needs to be freed
    char    **cmd1; // needs to be freed
    char    **cmd2; // needs to be freed
    char    *cmd_path1; // needs to be freed
    char    *cmd_path2; // needs to be freed
    char    **env;
}           t_data;

void	child_process(t_data *d);
void	parent_process(t_data *d);
int 	main(int argc, char *argv[], char **env);
char	*ft_strjoin_mod(const char *s1, const char *s2);
char    **bin_paths(t_data *d);
void	parse_cmds(char *argv[], t_data *d);
char	**combine_cmd_path(t_data *d, char *cmd[]);
int	    path_access(t_data *d, char *cmd_path);
int     path_access2(t_data *d, char *cmd_path);

#endif
