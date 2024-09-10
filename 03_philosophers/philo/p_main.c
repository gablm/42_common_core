/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:42:42 by gfragoso          #+#    #+#             */
/*   Updated: 2024/04/04 18:49:26 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	load_main_set(t_main *m, int i, int data)
{
	if (i == 0)
		m->count = data;
	if (i == 1)
		m->time_ms_die = data;
	if (i == 2)
		m->time_ms_eat = data;
	if (i == 3)
		m->time_ms_sleep = data;
	if (i == 4)
		m->n_must_eat = data;
}

int	load_main(t_main *m, int n, char **data)
{
	long	temp;
	int		i;

	i = 0;
	m->n_must_eat = -1;
	while (i < n)
	{
		temp = conv_and_verif(data[i]);
		if (temp <= 0 - (i == 4))
			return (i + 1);
		load_main_set(m, i, temp);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_main	main;
	int		i;

	if (argc < 5 || argc > 6)
	{
		printf("Error\nInvalid number of arguments\n");
		return (EXIT_FAILURE);
	}
	i = load_main(&main, argc - 1, argv + 1);
	if (i)
	{
		printf("Error\nInvalid argument [%d]\n", i);
		return (EXIT_FAILURE);
	}
	if (init_main(&main))
	{
		printf("Error\nCouldn't fully initialize main.\n");
		return (EXIT_FAILURE);
	}
	return (init_threads(&main));
}
