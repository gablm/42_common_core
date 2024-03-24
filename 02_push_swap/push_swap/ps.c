/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:49:51 by gfragoso          #+#    #+#             */
/*   Updated: 2023/10/24 22:04:42 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	fill_stack(char **str, t_stack *a, t_stack *b)
{
	int	i;

	a->list = malloc(sizeof(int) * a->len);
	if (!a->list)
		error_exit(NULL);
	i = 0;
	while (i < a->len)
	{
		a->list[i] = ft_str_atoi(str[i], a->list);
		i++;
	}
	if (has_duplicates(a))
		error_exit(a->list);
	b->list = malloc(sizeof(int) * a->len);
	if (!b->list)
		error_exit(a->list);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc <= 1)
		exit(EXIT_FAILURE);
	a.len = argc - 1;
	b.len = 0;
	fill_stack(argv + 1, &a, &b);
	sorter(&a, &b);
	free(a.list);
	free(b.list);
	return (0);
}
