/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:11:02 by gsims             #+#    #+#             */
/*   Updated: 2023/10/11 19:19:04 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char	*dst, const char	*src, size_t	dstsize)
{
	size_t	i;
	size_t	srcsize;

	i = 0;
	srcsize = ft_strlen(src);
	if (dstsize > srcsize)
	{
		while (i < dstsize && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
	}
	else if (dstsize <= srcsize)
		while (i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
	dst[i] = '\0';
	return (srcsize);
}
/*
int	main()
{
	const char	*src = "AAAAA";
	char		dst[8] = "BBBBBBB";
	size_t		dstsize  = 5;

	printf("source string: %s\n", src);
	printf("dest string: %s\n", dst);
	ft_strlcpy(dst, src, dstsize);
	printf("dest string after strlcpy function: %s\n", dst);
	printf("ft_strlcpy result: %zu\n", ft_strlcpy(dst, src, dstsize));
	return (0);
}*/
