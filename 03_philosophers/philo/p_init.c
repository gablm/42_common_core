/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:45:31 by gfragoso          #+#    #+#             */
/*   Updated: 2024/04/04 19:57:57 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	join_threads(t_main *main)
{
	int	i;

	i = 0;
	if (pthread_join(main->monitor, NULL))
		return (ERROR);
	while (i < main->count)
	{
		if (pthread_join(main->philos[i].thread, NULL))
			return (ERROR);
		i++;
	}
	return (OK);
}

int	init_threads(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->count)
	{
		pthread_create(&main->philos[i].thread, NULL,
			philo_loop, &main->philos[i]);
		i++;
	}
	pthread_create(&main->monitor, NULL, &check_loop, main);
	if (join_threads(main))
	{
		printf("Error\nCouldn't join threads.\n");
		return (ERROR);
	}
	if (delete_main(main))
	{
		printf("Error\nCouldn't delete main.\n");
		return (ERROR);
	}
	return (OK);
}
