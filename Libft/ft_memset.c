/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:33:47 by gsims             #+#    #+#             */
/*   Updated: 2023/10/09 15:30:58 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*ptr;
	unsigned char	uc;

	i = 0;
	uc = (unsigned char)c;
	ptr = b;
	while (i < len)
	{
		ptr[i] = uc;
		i++;
	}
}

void	ft_bzero(void	*s, size_t	n)
{
	ft_memset(s, 0, n);
}

void	*memcpy(void *restrict	dst, const void *restrict	src, size_t	n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	i = 0;
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
}

void	*memmove(void *dst, const void	*src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (s < d && s + len > d)
	{
		i = len;
		while (i > 0)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
}


/*
int main() 
{ 
    char str[50] = "blablabla 42424242 blablabla"; 
    printf("\nBefore memset(): %s\n", str); 
  
    // Fill 8 characters starting from str[13] with '.' 
	ft_memset(str + 3, 'A', 8*sizeof(char)); 
  
    printf("After memset():  %s", str); 
    return 0; 
}*/
