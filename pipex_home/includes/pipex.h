/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:43:38 by gsims             #+#    #+#             */
/*   Updated: 2024/01/04 18:41:03 by georgesims       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_data
{
	int		file1;
	int		file2;
	int		fd[2];
	char	**bin_paths;
	char	**cmd_paths1;
	char	**cmd_paths2;
	char	**cmd1;
	char	**cmd2;
	char	*cmd_path1;
	char	*cmd_path2;
}			t_data;

void		child_process(t_data *d, char *envp[]);
void		parent_process(t_data *d, char *envp[]);
int			main(int argc, char *argv[], char **env);
char		*ft_strjoin_mod(const char *s1, const char *s2);
char		**bin_paths(t_data *d, char *envp[]);
void		parse_cmds(char *argv[], t_data *d);
char		**combine_cmd_path(t_data *d, char *cmd[]);
int			path_access(t_data *d, char **cmd_path);
int			path_access2(t_data *d, char **cmd_path);
int			ft_count_array(char **array);
void		ft_free_array(char **array);
void		ft_free_all(t_data *d);

#endif
