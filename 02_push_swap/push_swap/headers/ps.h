/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:48:41 by gfragoso          #+#    #+#             */
/*   Updated: 2023/10/25 14:57:10 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include "libft.h"

typedef struct s_stack
{
	int	*list;
	int	len;
	int	min_cost;
	int	index_a;
	int	index_b;
}	t_stack;

# define INT_MAX 2147483647
# define INT_MIN -2147483648

// Utils
void	error_exit(int *l1);
void	print_list(t_list *a);
void	print_array(t_stack *a, t_stack *b);
int		ft_str_atoi(const char *nptr, int *l1);
int		is_sorted(t_stack *stk);
int		has_duplicates(t_stack *stk);

/* Swaps first two elems
sa(a, len_a);*/
int		sa(t_stack *a, t_list *out);
/* Swaps first two elems 
sb(b, len_b)*/
int		sb(t_stack *b, t_list *out);
/* Swaps first two elems from both stacks
ss(a, len_a, b, len_b)*/
int		ss(t_stack *a, t_stack *b, t_list *out);

// pa(b, len_b, a, len_a)
int		pa(t_stack *a, t_stack *b, t_list *out);
// pa(a, len_a, b, len_b)
int		pb(t_stack *a, t_stack *b, t_list *out);

/* Rotates up - First becomes last
ra(a, len_a)*/
int		ra(t_stack *a, t_list *out);
/* Rotates up - First becomes last
rb(b, len_b)*/
int		rb(t_stack *b, t_list *out);
/* Rotates both up - First becomes last
rr(a, len_a, b, len_b)*/
int		rr(t_stack *a, t_stack *b, t_list *out);

/* Rotates down - Last becomes first
rra(a, len_a)*/
int		rra(t_stack *a, t_list *out);
/* Rotates down - Last becomes first
rb(b, len_b)*/
int		rrb(t_stack *b, t_list *out);
/* Rotates both down - Last becomes first
rr(a, len_a, b, len_b)*/
int		rrr(t_stack *a, t_stack *b, t_list *out);

// Sorter
int		rotate(t_stack *stk);
int		rev_rotate(t_stack *stk);
void	sorter(t_stack *a, t_stack *b);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
void	scuff_free(void *p);
void	move_best(t_stack *a, t_stack *b, t_list *out);
void	rev_rotate_both(t_stack *a, t_stack *b, t_list *out);
void	rotate_both(t_stack *a, t_stack *b, t_list *out);
void	rr_a_r_b(t_stack *a, t_stack *b, t_list *out);
void	r_a_rr_b(t_stack *a, t_stack *b, t_list *out);
int		find_pos(t_stack *a, int val);
int		get_best_cost(int p_a, int p_b, int l_a, int l_b);
void	set_mincost(t_stack *a, t_stack *b, int rev);
int		find_min(t_stack *a);

// Sorters
void	sort_3(t_stack *stk, t_list *out);
void	sort_5(t_stack *a, t_stack *b, t_list *out);

#endif
