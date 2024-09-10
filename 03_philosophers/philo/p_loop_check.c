/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_loop_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:45:17 by gfragoso          #+#    #+#             */
/*   Updated: 2024/04/04 19:58:14 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	is_over(t_main *main)
{
	t_bool	done;

	pthread_mutex_lock(&main->mutex);
	done = main->is_over || main->full_count
		== main->count;
	pthread_mutex_unlock(&main->mutex);
	return (done);
}

int	check_eat(t_main *main)
{
	if (main->n_must_eat == -1)
		return (OK);
	if (is_over(main))
		return (ERROR);
	return (OK);
}

int	check_death(t_main *main)
{
	int		i;
	long	time;
	t_philo	*curr;

	i = 0;
	time = get_time();
	while (i < main->count)
	{
		curr = main->philos + i;
		pthread_mutex_lock(&curr->death);
		if (main->time_ms_die <= time - curr->eat_time)
		{
			print_action(main, act_die, curr->num);
			pthread_mutex_lock(&main->mutex);
			main->is_over = TRUE;
			pthread_mutex_unlock(&main->mutex);
			pthread_mutex_unlock(&curr->death);
			return (ERROR);
		}
		pthread_mutex_unlock(&curr->death);
		i++;
	}
	return (OK);
}

void	*check_loop(void *ptr)
{
	t_main	*main;

	main = (t_main *)ptr;
	while (1)
	{
		if (check_death(main))
			return (NULL);
		if (check_eat(main))
			return (NULL);
	}
	return (NULL);
}
