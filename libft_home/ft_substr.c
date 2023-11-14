/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:53:21 by gsims             #+#    #+#             */
/*   Updated: 2023/10/18 12:45:12 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	getlen(const char *s, unsigned int start, size_t len)
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
/*
int main()
{
	const char		*s = "012345";
	char			*result;
	unsigned int	start = 2;
	size_t			len = 5;

	result = ft_substr(s, start, len);
	printf("%s\n", result);
	return (0);
}*/
