/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_verify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:26:04 by gfragoso          #+#    #+#             */
/*   Updated: 2024/03/22 16:27:55 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	has_duplicates(t_stack *stk)
{
	int	i;
	int	j;

	i = 0;
	while (i < stk->len - 1)
	{
		j = i + 1;
		while (j < stk->len)
		{
			if (stk->list[i] == stk->list[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_sorted(t_stack *stk)
{
	int	i;

	i = 0;
	while (i < stk->len - 1)
	{
		if (stk->list[i] > stk->list[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_compare(int n, const char *a)
{
	char	*num;
	int		res;

	num = ft_itoa(n);
	res = ft_strncmp(num, a, 100);
	free(num);
	return (res);
}

int	ft_str_atoi(const char *nptr, int *l1)
{
	int	i;
	int	res;
	int	signal;

	i = 0;
	res = 0;
	signal = 1;
	if (!ft_isdigit(nptr[i]) && nptr[i] != '-')
		error_exit(l1);
	if (nptr[i] == '-')
	{
		signal *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	if ((!ft_isdigit(nptr[i]) && nptr[i] != '\0')
		|| ft_compare(res * signal, nptr))
		error_exit(l1);
	return (res * signal);
}

void	scuff_free(void *p)
{
	(void)p;
}
