/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:43:38 by gsims             #+#    #+#             */
/*   Updated: 2023/12/21 15:18:02 by georgesims       ###   ########.fr       */
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
    char    **bin_paths; // array of paths to binary exec files
    char    **cmd_paths1; // array of potential paths to binary exec files with arg appended
    char    **cmd_paths2; // array of potential paths to binary exec files with arg appended
    char    **cmd1; // array of commands and args from cmd1 (ex: ["ls", "-a"])
    char    **cmd2; // array of commands and args from cmd1 (ex: ["ls", "-a"])
    char    *cmd_path1; // working combination of binary path and appended arg
    char    *cmd_path2; // working combination of binary path and appended arg
}           t_data;

void	child_process(t_data *d, char *envp[]);
void	parent_process(t_data *d, char *envp[]);
int 	main(int argc, char *argv[], char **env);
char	*ft_strjoin_mod(const char *s1, const char *s2);
char    **bin_paths(t_data *d, char *envp[]);
void	parse_cmds(char *argv[], t_data *d);
char	**combine_cmd_path(t_data *d, char *cmd[]);
int	    path_access(t_data *d, char **cmd_path);
int     path_access2(t_data *d, char **cmd_path);

#endif
