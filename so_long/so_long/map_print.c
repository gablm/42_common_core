/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <gfragoso@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:56:10 by gfragoso          #+#    #+#             */
/*   Updated: 2024/03/22 14:50:31 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_mlx mlx, char *image, int x, int y)
{
	void	*img;
	int		s;
	int		size;
	int		size2;

	size = TILE_SIZE;
	size2 = TILE_SIZE;
	s = TILE_SIZE;
	img = mlx_xpm_file_to_image(mlx.ptr, image, &size, &size2);
	mlx_put_image_to_window(mlx.ptr, mlx.wdw, img, y * s, x * s);
	mlx_destroy_image(mlx.ptr, img);
}

void	print_tile(t_mlx mlx, t_tile tile, t_map map)
{
	if (tile.type == '0')
		put_image(mlx, "textures/zero64.xpm", tile.x, tile.y);
	else if (tile.type == '1')
		put_image(mlx, "textures/one64.xpm", tile.x, tile.y);
	else if (tile.type == 'C')
		put_image(mlx, "textures/coin64.xpm", tile.x, tile.y);
	else if (tile.type == 'E' && map.player.coins == map.total_coins)
		put_image(mlx, "textures/exit-open64.xpm", tile.x, tile.y);
	else if (tile.type == 'E')
		put_image(mlx, "textures/exit-close64.xpm", tile.x, tile.y);
	else if (tile.type == 'P')
		put_image(mlx, "textures/p64.xpm", tile.x, tile.y);
}

void	print_map(t_mlx mlx, t_map map)
{
	int	i;

	i = 0;
	while (i < map.size)
	{
		print_tile(mlx, map.tiles[i], map);
		i++;
	}
	print_tile(mlx, map.player.tile, map);
}
