/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:16:11 by gsims             #+#    #+#             */
/*   Updated: 2023/10/12 14:16:52 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numin(const char *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			counter++;
		i++;
	}
	return (counter);
}

int	ft_strlenuntil(const char *s, char c)
{
	int	res;

	res = 0;
	while (s[res] != c && s[res] != '\0')
		res++;
	return (res);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	int		rows;
	int		splits;
	char	**array;

	splits = ft_numin(s, c);
	array = (char **)malloc((splits + 1) * sizeof(char *));
	i = 0;
	rows = 0;
	while (i < ft_strlen(s))
	{
		array[rows] = (char *)malloc(ft_strlenuntil(&s[i], c) + 1);
		j = 0;
		while (s[i] != c && s[i] != '\0')
			array[rows][j++] = s[i++];
		array[rows][j] = '\0';
		rows++;
		i++;
	}
	array[rows] = NULL;
	return (array);
}
/*
int	main()
{
	const char	*s = "Hello-we-are-the-robots";
	char		c = '-';
	int 		i = 0;
	char		**array;

	array = ft_split(s, c);
	while (i < ft_numin(s, c) + 2)
	{
		printf("%s\n", array[i]);
		i++;
	}
	return (0);
}*/
