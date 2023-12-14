/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:16:11 by gsims             #+#    #+#             */
/*   Updated: 2023/10/18 12:31:55 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
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
	char	**array;

	array = (char **)malloc((ft_numin(s, c) + 1) * sizeof(char *));
	if (!array || !s)
		return (NULL);
	i = 0;
	rows = 0;
	while (rows != ft_numin(s, c))
	{
		if (s[i] != c)
		{
			array[rows] = (char *)malloc(ft_strlenuntil(&s[i], c) + 1);
			if (array[rows] == NULL)
				return (NULL);
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
*/

#include "libft.h"

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	size_t	word_len;
	int		i;

	lst = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!s || !lst)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				word_len = ft_strlen(s);
			else
				word_len = ft_strchr(s, c) - s;
			lst[i++] = ft_substr(s, 0, word_len);
			s += word_len;
		}
	}
	lst[i] = NULL;
	return (lst);
}
/*
int	main()
{
	const char	*s = "hello!zzhgfzzzzzz";
	char		c = 'z';
	int 		i = 122;
	char		**array;

	array = ft_split(s, c);
	while (i < ft_numin(s, c) + 1)
	{
		printf("%s\n", array[i]);
		i++;
	}
	return (0);
}*/
