/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:50:55 by gfragoso          #+#    #+#             */
/*   Updated: 2023/11/17 01:52:02 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_wdw(t_mlx *mlx)
{
	free(mlx->map->tiles);
	mlx_destroy_window(mlx->ptr, mlx->wdw);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
	exit(0);
	return (0);
}

void	error_exit(char *str)
{
	ft_printf("Error\nso_long: %s\n", str);
	exit(EXIT_FAILURE);
}
