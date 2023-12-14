/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:44:58 by gsims             #+#    #+#             */
/*   Updated: 2023/12/14 15:11:58 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// free full arrays
void	ft_free_array(char **array)
{
	int i;

	i = 0;
	while (*array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}