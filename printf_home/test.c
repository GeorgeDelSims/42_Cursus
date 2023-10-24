/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:20:16 by gsims             #+#    #+#             */
/*   Updated: 2023/10/24 15:05:11 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main()
{
	int	charcount;
	
	charcount = ft_printf("Hello %y %%x %u %i %X", 255, 255, 255, 255);
	printf("\n");
	charcount += ft_printchar_normal('%');
//	printf("charcount number: %d\n", charcount);
//	printf("ft_printint test: %d\n", ft_printint(42));
//	printf("ft_printchar test: \n");
//	ft_printchar(4);
	return (0);
}
