/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 08:25:05 by gsims             #+#    #+#             */
/*   Updated: 2023/10/11 16:07:18 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	basic_func(unsigned int index, char *s)
{
	s[index] = s[index] + 1;
}
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	while (i < len && s[i] != '\0')
	{
		f(i, s);
		i++;
	}
}
/*
int	main()
{
	char s[] = "AAA";

	ft_striteri(s, basic_func);
	printf("%s\n", s);
	return (0);
}*/
