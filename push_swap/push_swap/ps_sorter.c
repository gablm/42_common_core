/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:01:36 by gfragoso          #+#    #+#             */
/*   Updated: 2023/10/25 16:41:53 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	find_max_pos(t_stack *s)
{
	int	i;
	int	res;
	int	max;

	i = 0;
	res = 0;
	max = -2147483648;
	while (i < s->len)
	{
		if (s->list[i] > max)
		{
			max = s->list[i];
			res = i;
		}
		i++;
	}
	return (res);
}

void	rotate_till_max(t_stack *b, t_list *out)
{
	int	max;

	max = find_max_pos(b);
	while (max > 0 && max != b->len)
	{
		if (max <= b->len / 2)
		{
			rb(b, out);
			max--;
		}
		else
		{
			rrb(b, out);
			max++;
		}
	}
}

void	big_sort(t_stack *a, t_stack *b, t_list *out)
{
	int	i;

	i = -1;
	while (++i < 2)
		pb(a, b, out);
	while (a->len)
	{
		set_mincost(a, b, 0);
		move_best(a, b, out);
		pb(a, b, out);
	}
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

void	sorter(t_stack *a, t_stack *b)
{
	t_list	*output;

	if (is_sorted(a))
		return ;
	output = ft_lstnew("0");
	if (a->len == 2)
		sa(a, output);
	else if (a->len == 3)
		sort_3(a, output);
	else if (a->len == 5)
		sort_5(a, b, output);
	else
		big_sort(a, b, output);
	print_list(output);
	ft_lstclear(&output, scuff_free);
}
