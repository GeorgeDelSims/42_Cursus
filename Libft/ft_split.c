/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:16:11 by gsims             #+#    #+#             */
/*   Updated: 2023/10/13 10:34:42 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numin(const char *s, char c)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	if (ft_strlen(s) == 0)
		return (0);
	if (s[i] != c)
	{
		counter++;
		i++;
	}
	else if (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
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

char	*fill_rows(char *array, int i, const char *s, char c)
{
	int	j;

	j = 0;
	while (s[i] != c && s[i] != '\0')
		array[j++] = s[i++];
	array[j] = '\0';
	return (array);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		rows;
	int		splits;
	char	**array;

	splits = ft_numin(s, c);
	array = (char **)malloc((splits + 1) * sizeof(char *));
	i = 0;
	rows = 0;
	while (rows != splits)
	{
		if (s[i] != c)
		{
			array[rows] = (char *)malloc(ft_strlenuntil(&s[i], c) + 1);
			array[rows] = fill_rows(array[rows], i, s, c);
			i += ft_strlenuntil(&s[i], c);
			rows++;
		}
		else
			i++;
	}
	array[rows] = NULL;
	return (array);
}
/*
int	main()
{
	const char	*s = "";
	char		c = 'k';
	int 		i = 0;
	char		**array;

	array = ft_split(s, c);
	while (i < ft_numin(s, c) + 1)
	{
		printf("%s\n", array[i]);
		i++;
	}
	return (0);
}*/
