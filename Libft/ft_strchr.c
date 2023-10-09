/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:42:07 by gsims             #+#    #+#             */
/*   Updated: 2023/10/09 18:20:59 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	char	uc;

	uc = (char)c;
	while (*s != '\0')
	{
		if (*s == uc)
			return (char *)s;
		s++;
	}
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i != 0)
	{
		if (s[i] == (char)c)
			return (char *)s;
	}
}

int main()
{
	const char	*str = "HelloabcdAaa";
	int	c = 65;
	char	*ptr;
	
	ptr = ft_strrchr(str, c);
	printf("%c\n", *ptr);
	return (0);
}
