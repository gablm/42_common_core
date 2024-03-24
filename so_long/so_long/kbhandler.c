/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kbhandler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <gfragoso@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:16:02 by gfragoso          #+#    #+#             */
/*   Updated: 2024/03/22 13:57:45 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_tile	get_tile_at(t_map *map, int x, int y)
{
	return (map->tiles[x * map->w + y]);
}

int	verify_colision(t_mlx *mlx, int x, int y)
{
	t_tile	tilever;

	tilever = get_tile_at(mlx->map, x, y);
	if (tilever.type == '1')
		return (0);
	if (tilever.type == 'C')
	{
		mlx->map->tiles[x * mlx->map->w + y].type = '0';
		mlx->map->player.coins++;
		return (1);
	}
	if (tilever.type == 'E' && mlx->map->player.coins == mlx->map->total_coins)
	{
		ft_printf("Move count: %d\n", mlx->move_count + 1);
		close_wdw(mlx);
	}
	return (1);
}

void	move_player(t_mlx *mlx, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = mlx->map->player.tile.x + x;
	new_y = mlx->map->player.tile.y + y;
	if (verify_colision(mlx, new_x, new_y))
	{
		mlx->map->player.tile.x += x;
		mlx->map->player.tile.y += y;
		mlx->move_count++;
		ft_printf("Move count: %d\n", mlx->move_count);
		print_map(*mlx, *mlx->map);
	}
}

int	handle_keys(int keycode, t_mlx *mlx)
{
	if (keycode == 0xff1b)
		close_wdw(mlx);
	if (keycode == 0xff52 || keycode == 0x77)
		move_player(mlx, -1, 0);
	if (keycode == 0xff54 || keycode == 0x73)
		move_player(mlx, 1, 0);
	if (keycode == 0xff51 || keycode == 0x61)
		move_player(mlx, 0, -1);
	if (keycode == 0xff53 || keycode == 0x64)
		move_player(mlx, 0, 1);
	return (0);
}
