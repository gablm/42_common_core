/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:26:23 by gfragoso          #+#    #+#             */
/*   Updated: 2023/10/25 16:46:26 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int	push(t_stack *stk1, t_stack *stk2)
{
	int	temp;

	if (!stk1->list || !stk2->list)
		error_exit(NULL);
	if (stk1->len < 1)
		return (0);
	rotate(stk1);
	stk1->len -= 1;
	temp = stk1->list[stk1->len];
	stk2->list[stk2->len] = temp;
	stk2->len += 1;
	rev_rotate(stk2);
	return (1);
}

// pa(list a, list b)
int	pa(t_stack *a, t_stack *b, t_list *out)
{
	push(a, b);
	ft_lstadd_back(&out, ft_lstnew("pa"));
	return (1);
}

// pb(list b, list a)
int	pb(t_stack *b, t_stack *a, t_list *out)
{
	push(b, a);
	ft_lstadd_back(&out, ft_lstnew("pb"));
	return (1);
}
