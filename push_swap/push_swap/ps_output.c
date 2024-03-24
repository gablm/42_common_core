/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:05:06 by gfragoso          #+#    #+#             */
/*   Updated: 2024/03/22 16:28:21 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	streq(char *one, char *two)
{
	if (!one || !two)
		return (0);
	return (ft_strncmp(one, two, __INT64_MAX__) == 0);
}

int	double_print(char *now, char *next)
{
	if (streq(now, "sb") && streq(next, "sa"))
		ft_putendl_fd("ss", 1);
	else if (streq(now, "sa") && streq(next, "sb"))
		ft_putendl_fd("ss", 1);
	else if (streq(now, "ra") && streq(next, "rb"))
		ft_putendl_fd("rr", 1);
	else if (streq(now, "rb") && streq(next, "ra"))
		ft_putendl_fd("rr", 1);
	else if (streq(now, "rra") && streq(next, "rrb"))
		ft_putendl_fd("rrr", 1);
	else if (streq(now, "rrb") && streq(next, "rra"))
		ft_putendl_fd("rrr", 1);
	else
		return (0);
	return (1);
}

void	print_list(t_list *a)
{
	char	*curr;
	char	*next;

	a = a->next;
	while (a)
	{
		curr = (char *)a->content;
		if (a->next)
		{
			next = (char *)a->next->content;
			if (double_print(curr, next))
			{
				a = a->next->next;
				continue ;
			}
		}
		ft_putendl_fd(curr, 1);
		a = a->next;
	}
}
