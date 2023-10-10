/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 08:51:39 by gsims             #+#    #+#             */
/*   Updated: 2023/10/10 09:01:22 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char	*s1, const char	*s2, size_t	n)
{
	size_t	i;
	int		res;

	i = 0;
	res = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		res = s1[i] - s2[i];
		i++;
	}
	return (res);
}
