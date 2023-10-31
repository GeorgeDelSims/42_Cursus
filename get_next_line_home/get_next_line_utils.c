/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:27:24 by gsims             #+#    #+#             */
/*   Updated: 2023/10/31 15:02:24 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//Determines the length of a string
int	ft_strlen(const char *s)
{
	int	res;

	res = 0;
	if(s)
	{
		while (s[res] != '\0')
			res++;
	}
	return (res);
}

//Determines the length of a line 
int line_len(char *str)
{
    int i;
    
    i = 0;
    while (*str != '\n')
        i++;
    return (i);
}

//joins / concatenates two strings into a new one with dynamic memory allocation
char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*newstr;
	int		i;
	int		j;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	newstr = (char *)malloc((len + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	i = 0;
	if(s1)
	{
		while (i < len && s1[i] != '\0')
		{
			newstr[i] = s1[i];
			i++;
		}
	}
	j = 0;
	if(s2)
	{
		while (i < len && s2[j] != '\0')
		{
			newstr[i] = s2[j];
			i++;
			j++;
		}
	}
	newstr[i] = '\0';
	return (newstr);
}

//strchr function
char	*ft_strchr(const char *s, int c)
{
	char	uc;
	int		i;

	uc = (char)c;
	if (uc == '\0')
	{
		i = ft_strlen(s);
		return ((char *)&s[i]);
	}
	else
	{
		i = 0;
		while (s[i] != '\0')
		{
			if (s[i] == uc)
				return ((char *)&s[i]);
			i++;
		}
		return (NULL);
	}
}

// Function helper for ft_substr
static int	getlen(const char *s, unsigned int start, size_t len)
{
	unsigned int	s_len;

	s_len = (unsigned int)ft_strlen(s);
	if (start >= s_len)
		return (0);
	if (s_len - start < len)
		return (s_len - start);
	else
		return (len);
}

//substring from string s (starting at index start and of length len)
//returns substring
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	substr = (char *)malloc((getlen(s, start, len) + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
				substr[j] = s[i];
				j++;
		}
		i++;
	}
	substr[j] = '\0';
	return (substr);
}