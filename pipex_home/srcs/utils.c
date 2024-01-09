/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:44:58 by gsims             #+#    #+#             */
/*   Updated: 2024/01/09 14:30:38 by gsims            ###   ########.fr       */
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
	close(d->fd[0]);
	close(d->fd[1]);
	free(d);
}

int	ft_count_array(char **array)
{
	int	count;

	count = 0;
	while (array[count])
		count++;
	return (count);
}

void	ft_print_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		ft_printf("%s\n", array[i]);
		i++;
	}
}

char	*ft_strjoin_mod(const char *s1, const char *s2)
{
	char	*newstr;
	int		i;
	int		j;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	newstr = (char *)malloc((len + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	ft_bzero(newstr, len + 1);
	i = 0;
	while (i < len && s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
	newstr[i] = '/';
	i++;
	j = 0;
	while (i < len && s2[j] != '\0')
		newstr[i++] = s2[j++];
	newstr[i] = '\0';
	return (newstr);
}
