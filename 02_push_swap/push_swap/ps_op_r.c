/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:35:22 by gfragoso          #+#    #+#             */
/*   Updated: 2023/10/25 16:46:20 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	rotate(t_stack *stk)
{
	int	i;
	int	temp;

	if (!stk->list)
		error_exit(NULL);
	if (stk->len <= 1)
		return (0);
	i = 0;
	temp = stk->list[0];
	while (i < stk->len - 1)
	{
		stk->list[i] = stk->list[i + 1];
		i++;
	}
	stk->list[stk->len - 1] = temp;
	return (1);
}

// Rotates up - First becomes last
int	ra(t_stack *a, t_list *out)
{
	rotate(a);
	ft_lstadd_back(&out, ft_lstnew("ra"));
	return (1);
}

// Rotates up - First becomes last
int	rb(t_stack *b, t_list *out)
{
	rotate(b);
	ft_lstadd_back(&out, ft_lstnew("rb"));
	return (1);
}

// Rotates both up - First becomes last
int	rr(t_stack *a, t_stack *b, t_list *out)
{
	rotate(a);
	rotate(b);
	ft_lstadd_back(&out, ft_lstnew("rr"));
	return (1);
}
