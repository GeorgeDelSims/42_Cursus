/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:41:46 by gsims             #+#    #+#             */
/*   Updated: 2024/01/02 11:52:25 by georgesims       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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

// Test if these paths can be accessed and execve if they can
int	path_access(t_data *d, char **cmd_path)
{
	int	i;

	i = 0;
	while (d->cmd_paths1[i])
	{
		if (access(d->cmd_paths1[i], X_OK) == 0)
		{
			*cmd_path = ft_strdup(d->cmd_paths1[i]); // Malloc !!! 
			return (1);
		}
		i++;
	}
	perror("path invalid or cannot be accessed.");
	return (0);
}

// Test if these paths can be accessed and execve if they can
int	path_access2(t_data *d, char **cmd_path)
{
	int	i;

	i = 0;
	while (d->cmd_paths2[i])
	{
		if (access(d->cmd_paths2[i], X_OK) == 0)
		{
			*cmd_path = ft_strdup(d->cmd_paths2[i]); // Malloc !!! 
			return (1);
		}
		i++;
	}
	ft_printf("path invalid or cannot be accessed.\n");
	return (0);
}


/*
int	main()
{
	const char	*s1 = "helloDFSFSDFT  ";
	const char	*s2 = "com";

	printf("%s\n", ft_strjoin_mod(s1, s2));
	return (0);
}*/
