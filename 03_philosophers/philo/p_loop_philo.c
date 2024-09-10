/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_loop_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:45:17 by gfragoso          #+#    #+#             */
/*   Updated: 2024/04/04 19:56:19 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_think(t_philo *philo)
{
	if (is_over(philo->main))
		return (ERROR);
	if (print_action(philo->main, act_think, philo->num))
		return (ERROR);
	if (philo->num % 2 == 0 && philo->main->count % 2)
		usleep((philo->main->time_ms_eat * 2
				- philo->main->time_ms_sleep) * 500);
	else
		usleep(1000);
	return (OK);
}

int	philo_sleep(t_philo *philo)
{
	if (is_over(philo->main))
		return (ERROR);
	if (print_action(philo->main, act_sleep, philo->num))
		return (ERROR);
	usleep(philo->main->time_ms_sleep * 1000);
	return (OK);
}

int	philo_get_forks(t_philo *philo)
{
	if (is_over(philo->main))
		return (ERROR);
	if (philo->num % 2)
	{
		pthread_mutex_lock(philo->right);
		print_action(philo->main, act_fork, philo->num);
		pthread_mutex_lock(philo->left);
		print_action(philo->main, act_fork, philo->num);
	}
	else
	{
		pthread_mutex_lock(philo->left);
		print_action(philo->main, act_fork, philo->num);
		pthread_mutex_lock(philo->right);
		print_action(philo->main, act_fork, philo->num);
	}
	return (OK);
}

int	philo_eat(t_philo *philo)
{
	if (is_over(philo->main))
	{
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		return (ERROR);
	}
	pthread_mutex_lock(&philo->death);
	philo->eat_time = get_time();
	philo->eat_count += 1;
	print_action(philo->main, act_eat, philo->num);
	pthread_mutex_lock(&philo->main->mutex);
	if (philo->eat_count == philo->main->n_must_eat)
		philo->main->full_count += 1;
	pthread_mutex_unlock(&philo->main->mutex);
	pthread_mutex_unlock(&philo->death);
	usleep(philo->main->time_ms_eat * 1000);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	return (OK);
}

void	*philo_loop(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->main->count == 1)
	{
		pthread_mutex_lock(philo->left);
		print_action(philo->main, act_fork, philo->num);
		pthread_mutex_unlock(philo->left);
		return (NULL);
	}
	if (philo->num % 2 == 0)
		usleep(1000);
	while (1)
	{
		if (philo_think(philo))
			return (NULL);
		if (philo_get_forks(philo))
			return (NULL);
		if (philo_eat(philo))
			return (NULL);
		if (philo_sleep(philo))
			return (NULL);
	}
	return (NULL);
}
