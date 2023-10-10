/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:12:07 by gsims             #+#    #+#             */
/*   Updated: 2023/10/10 13:12:30 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *restrict	dst, const char	*src, size_t	dstsize)
{
	size_t	i;
	size_t	j;

	if (dstsize > 0)
	{
		i = 0;
		while (dst[i] != '\0' && i < dstsize)
			i++;
		j = 0;
		while (src[j] != '\0' && i < dstsize)
		{
			dst[i] = src[j];
			j++;
			i++;
		}
		dst[i] = '\0';
		return (ft_strlen(dst) + ft_strlen(src));
	}
	else
		return (0);
}
