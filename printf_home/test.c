
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:06:57 by gsims             #+#    #+#             */
/*   Updated: 2023/10/25 10:41:23 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	main()
{
	int	charcount;
	char *ptr;

	ptr = (char *)malloc(sizeof(char) + 1);
	charcount = ft_printf(" %p ", 16);
	printf("\n");
	printf("%d\n", printf(" %p ", (void*)16));
	printf("\n");
//	charcount += ft_printchar_normal('%');
	printf("charcount number: %d\n", charcount);
//	printf("ft_printint test: %d\n", ft_printint(42));
//	printf("ft_printchar test: \n");
//	ft_printchar(4);
	return (0);
}