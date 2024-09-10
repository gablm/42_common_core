/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:57:12 by gfragoso          #+#    #+#             */
/*   Updated: 2024/03/26 12:57:25 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	tm;

	gettimeofday(&tm, NULL);
	return ((tm.tv_sec * 1000) + (tm.tv_usec * 0.001));
}

long	get_elapsed_time(long time)
{
	long	curr_time;

	curr_time = get_time();
	return (curr_time - time);
}

char	*act_to_str(t_action action)
{
	if (action == act_fork)
		return ("has taken a fork");
	if (action == act_eat)
		return ("is eating");
	if (action == act_sleep)
		return ("is sleeping");
	if (action == act_think)
		return ("is thinking");
	if (action == act_die)
		return ("died");
	return ("is confused and the action is invalid");
}

int	print_action(t_main *main, t_action action, int num)
{
	if (is_over(main))
		return (ERROR);
	pthread_mutex_lock(&main->print);
	printf("%li %i %s\n", get_elapsed_time(main->start),
		num, act_to_str(action));
	pthread_mutex_unlock(&main->print);
	return (OK);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && i < n)
	{
		if (s2[i] == '\0' || s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (s2[i] != '\0' && i != n)
		return (s1[i] - s2[i]);
	return (0);
}
