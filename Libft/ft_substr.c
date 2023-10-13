/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:53:21 by gsims             #+#    #+#             */
/*   Updated: 2023/10/13 13:52:37 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	getlen(const char *s, unsigned int start, size_t len)
{
	unsigned int	s_len;
	unsigned int	res;

	s_len = (unsigned int)ft_strlen(s);
	if (len == 0)
		return (0);
	else if (start >= s_len)
		res = 0;
	else if (start <= s_len && start + (unsigned int)len > s_len)
		res = s_len - start;
	else
		res = start + (unsigned int)len;
	return (res);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	substr = (char *)malloc((getlen(s, start, len) + 1) * sizeof(*s));
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
	const char		*s = "hola";
	char			*result;
	unsigned int	start = 2;
	size_t			len = 0;

	result = ft_substr(s, start, len);
	printf("%s\n", result);
	return (0);
}*/
