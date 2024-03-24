/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:51:58 by gfragoso          #+#    #+#             */
/*   Updated: 2024/03/22 16:56:56 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	error_exit(int *l1)
{
	if (l1)
		free(l1);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	find_pos(t_stack *a, int val)
{
	int	i;
	int	max;
	int	pos;

	i = a->len - 1;
	pos = 0;
	max = INT_MIN;
	while (i >= 0)
	{
		if (a->list[i] > max)
		{
			max = a->list[i];
			pos = i;
		}
		if (i > 0 && val < a->list[i - 1] && val > a->list[i])
			return (i);
		i--;
	}
	if (a->len > 0 && val > a->list[0] && val < a->list[a->len - 1])
		return (0);
	return (pos);
}

int	find_pos_min(t_stack *a, int val)
{
	int	i;
	int	max;
	int	pos;

	i = 0;
	pos = 0;
	max = INT_MAX;
	while (i < a->len)
	{
		if (a->list[i] < max)
		{
			max = a->list[i];
			pos = i;
		}
		if (i > 0 && val > a->list[i - 1] && val < a->list[i])
			return (i);
		i++;
	}
	if (a->len > 0 && val < a->list[0] && val > a->list[a->len - 1])
		return (0);
	return (pos);
}

int	get_best_cost(int p_a, int p_b, int l_a, int l_b)
{
	if (p_a < l_a / 2 && p_b < l_b / 2)
		return (p_a + p_b);
	if (p_a >= l_a / 2 && p_b >= l_b / 2)
		return (l_a - p_a + l_b - p_b);
	if (p_a < l_a / 2 && p_b >= l_b / 2)
		return (p_a + l_b - p_b);
	if (p_a >= l_a / 2 && p_b < l_b / 2)
		return (l_a - p_a + p_b);
	return (INT_MAX);
}

void	set_mincost(t_stack *a, t_stack *b, int rev)
{
	int	i;
	int	pos;
	int	cost;

	i = -1;
	a->min_cost = INT_MAX;
	while (++i < a->len)
	{
		if (rev)
			pos = find_pos_min(b, a->list[i]);
		else
			pos = find_pos(b, a->list[i]);
		cost = get_best_cost(i, pos, a->len, b->len);
		if (cost < a->min_cost)
		{
			a->min_cost = cost;
			a->index_a = i;
			a->index_b = pos;
		}
	}
}
