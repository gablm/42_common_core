/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_init_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:49:42 by gfragoso          #+#    #+#             */
/*   Updated: 2024/04/04 19:40:09 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	get_new_philo(t_main *main, int num)
{
	t_philo	ph;

	ph.main = main;
	ph.num = num;
	ph.eat_count = 0;
	ph.eat_time = get_time();
	return (ph);
}

int	init_philos(t_main *main)
{
	int		i;
	t_philo	ph;

	i = 0;
	main->philos = malloc(main->count * sizeof(t_philo));
	if (main->philos == NULL)
		return (ERROR);
	while (i < main->count)
	{
		ph = get_new_philo(main, i + 1);
		ph.left = main->forks + i;
		ph.right = main->forks + (i + 1) * (i != main->count - 1);
		if (pthread_mutex_init(&ph.death, NULL))
			return (ERROR);
		main->philos[i] = ph;
		i++;
	}
	return (OK);
}

int	init_forks(t_main *main)
{
	int	i;

	i = 0;
	main->forks = malloc(main->count * sizeof(pthread_mutex_t));
	if (!main->forks)
		return (ERROR);
	while (i < main->count)
	{
		if (pthread_mutex_init(main->forks + i, NULL))
			return (ERROR);
		i++;
	}
	return (OK);
}

int	init_main(t_main *main)
{
	main->is_over = 0;
	main->full_count = 0;
	main->start = get_time();
	if (pthread_mutex_init(&main->mutex, NULL))
		return (ERROR);
	if (pthread_mutex_init(&main->print, NULL))
		return (ERROR);
	if (init_forks(main))
		return (ERROR);
	if (init_philos(main))
		return (ERROR);
	return (OK);
}
