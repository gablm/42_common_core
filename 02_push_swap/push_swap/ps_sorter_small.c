/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorter_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 23:03:04 by gfragoso          #+#    #+#             */
/*   Updated: 2024/03/22 16:27:47 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	sort_3(t_stack *stk, t_list *out)
{
	int	*l1;

	l1 = stk->list;
	if (is_sorted(stk))
		return ;
	if (l1[2] < l1[1] && l1[1] < l1[0])
	{
		sa(stk, out);
		rra(stk, out);
	}
	else if (l1[0] < l1[1] && l1[1] > l1[2] && l1[0] < l1[2])
	{
		rra(stk, out);
		sa(stk, out);
	}
	else if (l1[0] > l1[1] && l1[1] < l1[2] && l1[0] < l1[2])
		sa(stk, out);
	else if (l1[0] > l1[1] && l1[2] > l1[1])
		ra(stk, out);
	else
		rra(stk, out);
}

int	find_min(t_stack *a)
{
	int	i;
	int	min;
	int	pos;

	i = 0;
	min = a->list[0];
	pos = 0;
	while (i < a->len)
	{
		if (a->list[i] < min)
		{
			min = a->list[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

void	sort_5(t_stack *a, t_stack *b, t_list *out)
{
	int	i;

	i = -1;
	while (++i < 2)
		pb(a, b, out);
	sort_3(a, out);
	while (b->len)
	{
		set_mincost(b, a, 1);
		a->index_a = b->index_b;
		a->index_b = b->index_a;
		move_best(a, b, out);
		pa(b, a, out);
	}
	a->index_a = find_min(a);
	a->index_b = 0;
	move_best(a, b, out);
}
