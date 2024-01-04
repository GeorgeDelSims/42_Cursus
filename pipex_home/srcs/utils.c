/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:44:58 by gsims             #+#    #+#             */
/*   Updated: 2024/01/04 16:54:53 by georgesims       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// free full arrays
void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_free_all(t_data *d)
{
	ft_free_array(d->bin_paths);
	ft_free_array(d->cmd_paths1);
	ft_free_array(d->cmd_paths2);
	ft_free_array(d->cmd1);
	ft_free_array(d->cmd2);
	free(d);
}