/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:26:53 by gfragoso          #+#    #+#             */
/*   Updated: 2023/10/25 16:45:59 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int	swap(t_stack *stk)
{
	int	temp;

	if (!stk->list)
		error_exit(NULL);
	if (stk->len <= 1)
		return (0);
	temp = stk->list[0];
	stk->list[0] = stk->list[1];
	stk->list[1] = temp;
	return (1);
}

int	sa(t_stack *a, t_list *out)
{
	swap(a);
	ft_lstadd_back(&out, ft_lstnew("sa"));
	return (1);
}

int	sb(t_stack *b, t_list *out)
{
	swap(b);
	ft_lstadd_back(&out, ft_lstnew("sb"));
	return (1);
}

int	ss(t_stack *a, t_stack *b, t_list *out)
{
	swap(a);
	swap(b);
	ft_lstadd_back(&out, ft_lstnew("ss"));
	return (1);
}
