/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:53:21 by gsims             #+#    #+#             */
/*   Updated: 2023/10/13 10:39:48 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	substr = (char *)malloc((len + 1) * sizeof(char));
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
	const char		*s = "hoolaaaaaaaaaaaaaaaaa";
	char			*result;
	unsigned int	start = 3;
	size_t			len = 3;

	result = ft_substr(s, start, len);
	printf("%s\n", result);
	return (0);
}*/
