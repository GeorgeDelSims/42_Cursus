/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:12:50 by gsims             #+#    #+#             */
/*   Updated: 2023/10/10 13:06:48 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*us;

	us = (const unsigned char *)s;
	i = 0;
	while (us[i] != '\0' && i < n)
	{
		if (us[i] == (unsigned char)c)
			return ((void *)&us[i]);
		i++;
	}
	return (0);
}
/*
int	main()
{
	const char *s = "dsfsd42A4352";
	int	c = 65;
	size_t n = 15;
	void	*ptr;
	
	ptr = ft_memchr(s, c, n);
	printf("%c\n", *(char *)ptr);	
	return(0);
}*/
