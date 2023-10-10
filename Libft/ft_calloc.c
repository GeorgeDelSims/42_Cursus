/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:29:42 by gsims             #+#    #+#             */
/*   Updated: 2023/10/10 14:48:17 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	n;
	void	*s;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	n = count * size;
	s = (void *)malloc(n);
	if (s == NULL)
		return (NULL);
	else
		ft_bzero(s, n);
	return (n);
}
