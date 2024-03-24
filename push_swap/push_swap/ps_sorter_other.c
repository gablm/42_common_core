/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorter_other.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 22:03:24 by gfragoso          #+#    #+#             */
/*   Updated: 2024/03/22 16:27:43 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	move_best(t_stack *a, t_stack *b, t_list *out)
{
	if (a->index_a <= a->len / 2 && a->index_b <= b->len / 2)
		rotate_both(a, b, out);
	else if (a->index_a > a->len / 2 && a->index_b > b->len / 2)
		rev_rotate_both(a, b, out);
	else if (a->index_a <= a->len / 2 && a->index_b > b->len / 2)
		r_a_rr_b(a, b, out);
	else if (a->index_a > a->len / 2 && a->index_b <= b->len / 2)
		rr_a_r_b(a, b, out);
}

void	rev_rotate_both(t_stack *a, t_stack *b, t_list *out)
{
	while (a->index_a < a->len && a->index_b < b->len)
	{
		rrr(a, b, out);
		a->index_a += 1;
		a->index_b += 1;
	}
	while (a->index_a < a->len)
	{
		rra(a, out);
		a->index_a += 1;
	}
	while (a->index_b < b->len)
	{
		rrb(b, out);
		a->index_b += 1;
	}
}

void	rotate_both(t_stack *a, t_stack *b, t_list *out)
{
	while (a->index_a > 0 && a->index_b > 0)
	{
		rr(a, b, out);
		a->index_a -= 1;
		a->index_b -= 1;
	}
	while (a->index_a > 0)
	{
		ra(a, out);
		a->index_a -= 1;
	}
	while (a->index_b > 0)
	{
		rb(b, out);
		a->index_b -= 1;
	}
}

void	rr_a_r_b(t_stack *a, t_stack *b, t_list *out)
{
	while (a->index_a < a->len)
	{
		rra(a, out);
		a->index_a += 1;
	}
	while (a->index_b > 0)
	{
		rb(b, out);
		a->index_b -= 1;
	}
}

void	r_a_rr_b(t_stack *a, t_stack *b, t_list *out)
{
	while (a->index_b < b->len)
	{
		rrb(b, out);
		a->index_b += 1;
	}
	while (a->index_a > 0)
	{
		ra(a, out);
		a->index_a -= 1;
	}
}
