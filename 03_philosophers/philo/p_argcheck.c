/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_argcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:57:03 by gfragoso          #+#    #+#             */
/*   Updated: 2024/03/26 14:20:47 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	ft_abs(long c)
{
	if (c < 0)
		return (-c);
	return (c);
}

static int	ft_ndivs(long n)
{
	int	res;

	res = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		res++;
		n *= -1;
	}
	while (n != 0)
	{
		n /= 10;
		res++;
	}
	return (res);
}

char	*safe_ltoa(long n)
{
	int		i;
	char	*res;

	i = ft_ndivs(n);
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (res == NULL)
		return (NULL);
	res[i--] = 0;
	if (n == 0)
		res[i] = '0';
	if (n < 0)
		return (free(res), NULL);
	while (n != 0)
	{
		res[i--] = '0' + ft_abs(n % 10);
		n /= 10;
	}
	return (res);
}

long	safe_positive_atol(const char *s)
{
	int		i;
	long	res;

	i = 0;
	res = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + s[i] - '0';
		i++;
	}
	if (s[i] && (s[i] < '0' || s[i] > '9'))
		return (-1);
	return (res);
}

long	conv_and_verif(char *s)
{
	long	res;
	char	*bck;

	if (s == NULL)
		return (ERROR);
	res = safe_positive_atol(s);
	bck = safe_ltoa(res);
	if (bck == NULL)
		return (ISH);
	if (ft_strncmp(s, bck, INT_MAX))
		return (free(bck), ISH);
	return (free(bck), res);
}
