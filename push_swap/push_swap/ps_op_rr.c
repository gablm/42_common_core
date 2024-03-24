/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:26:05 by gfragoso          #+#    #+#             */
/*   Updated: 2023/10/25 16:46:09 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	rev_rotate(t_stack *stk)
{
	int	i;
	int	temp;

	if (!stk->list)
		error_exit(NULL);
	if (stk->len <= 1)
		return (0);
	i = stk->len - 1;
	temp = stk->list[stk->len - 1];
	while (i > 0)
	{
		stk->list[i] = stk->list[i - 1];
		i--;
	}
	stk->list[0] = temp;
	return (1);
}

// Rotates down - Last becomes first
int	rra(t_stack *a, t_list *out)
{
	rev_rotate(a);
	ft_lstadd_back(&out, ft_lstnew("rra"));
	return (1);
}

// Rotates down - Last becomes first
int	rrb(t_stack *b, t_list *out)
{
	rev_rotate(b);
	ft_lstadd_back(&out, ft_lstnew("rrb"));
	return (1);
}

// Rotates both down - Last becomes first
int	rrr(t_stack *a, t_stack *b, t_list *out)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_lstadd_back(&out, ft_lstnew("rrr"));
	return (1);
}
