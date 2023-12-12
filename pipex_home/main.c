/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:04:53 by gsims             #+#    #+#             */
/*   Updated: 2023/12/12 14:50:13 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// Main Function takes all four args as input 
// arg[1] and arg[4] are file names
// arg[2] and arg[3] are shell commands.
// the result of cmd1 being applied to file1 needs to be fed to cmd2 and applied to file2.

#include "pipex.h"

int	main(int argc, char *argv[])
{
	int		fd1;
	int		fd2;
	
	if (argc != 5)
		return (0);

	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	
}
