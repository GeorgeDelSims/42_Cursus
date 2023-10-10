/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:53:21 by gsims             #+#    #+#             */
/*   Updated: 2023/10/10 15:06:59 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;

	i = 0;
	substr = (char *)malloc((len + 1) * sizeof(char));
	while (s[start] != '\0' && i < len)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	return (substr);
}
/*
int main()
{
	const char *s = "string example for the long ting";
	unsigned int	start = 12;
	size_t	len = 4;

	printf("%s\n", ft_substr(s, start, len));
	return (0);
}*/
