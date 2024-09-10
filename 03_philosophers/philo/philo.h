/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:03:55 by gfragoso          #+#    #+#             */
/*   Updated: 2024/03/26 16:14:13 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>
# include <pthread.h>

typedef int				t_bool;

# define TRUE 1
# define FALSE 0
# define ISH -1

# define ERROR -1
# define OK 0

# define INT_MAX 2147483648

typedef struct s_main	t_main;
typedef struct s_philo	t_philo;

typedef enum e_action
{
	act_fork,
	act_eat,
	act_sleep,
	act_think,
	act_die
}	t_action;

struct s_main
{
	pthread_t		monitor;
	pthread_mutex_t	mutex;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
	t_philo			*philos;
	int				count;

	long			time_ms_die;
	long			time_ms_eat;
	long			time_ms_sleep;
	long			n_must_eat;

	t_bool			is_over;
	long			start;
	long			full_count;
};

struct s_philo
{
	t_main			*main;
	pthread_t		thread;

	int				num;
	long			eat_count;
	long			eat_time;

	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	death;
};

// Init
int		init_main(t_main *main);
int		init_threads(t_main *main);

// Delete
int		delete_main(t_main *main);

// Loops
void	*check_loop(void *ptr);
void	*philo_loop(void *ptr);
t_bool	is_over(t_main *main);

// Output
int		print_action(t_main *a, t_action action, int num);

// Utils
int		ft_strncmp(const char *s1, const char *s2, size_t n);
long	conv_and_verif(char *s);

// Time
long	get_time(void);
long	get_elapsed_time(long time);

#endif
