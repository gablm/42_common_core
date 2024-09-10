/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_delete.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:38:34 by gfragoso          #+#    #+#             */
/*   Updated: 2024/04/04 18:46:10 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	delete_forks(t_main *main)
{
	int		i;

	if (main == NULL || main->forks == NULL)
		return (OK);
	i = 0;
	while (i < main->count)
	{
		if (pthread_mutex_destroy(main->forks + i))
			return (ERROR);
		i++;
	}
	free(main->forks);
	main->forks = NULL;
	return (OK);
}

int	delete_philo(t_main *main)
{
	int		i;
	t_philo	*curr;

	if (main == NULL || main->philos == NULL)
		return (OK);
	i = 0;
	while (i < main->count)
	{
		curr = main->philos + i;
		if (pthread_mutex_destroy(&curr->death))
			return (ERROR);
		i++;
	}
	free(main->philos);
	main->philos = NULL;
	return (OK);
}

int	delete_main(t_main *main)
{
	if (pthread_mutex_destroy(&main->mutex))
		return (ERROR);
	if (pthread_mutex_destroy(&main->print))
		return (ERROR);
	if (delete_forks(main))
		return (ERROR);
	if (delete_philo(main))
		return (ERROR);
	return (OK);
}
