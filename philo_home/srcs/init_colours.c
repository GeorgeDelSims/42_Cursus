/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colours.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:09:58 by gsims             #+#    #+#             */
/*   Updated: 2024/02/27 14:10:24 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// initiate colour array
void	init_colours(t_data *d)
{
	d->colours[0] = GREEN;
	d->colours[1] = YELLOW;
	d->colours[2] = BLUE;
	d->colours[3] = PURPLE;
	d->colours[4] = CYAN;
	d->colours[5] = RED;
}
