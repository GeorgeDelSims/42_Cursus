/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:37:28 by gsims             #+#    #+#             */
/*   Updated: 2024/02/27 14:01:29 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// Main function
int	main(int ac, char *av[])
{
	t_data	*d;

	if ((input_check(ac, av)) == 0)
	{
		printf("input incorrect\n");
		return (0);
	}
	d = (t_data *)malloc(sizeof(t_data));
	if (!d)
		return (0);
	if (init_data(d, av) == 0)
		return (0);
	if (d->number_of_philosophers != 1)
		philosophers(d);
	else 
		case_one(d);
	free_all(d);
	return (0);
}
