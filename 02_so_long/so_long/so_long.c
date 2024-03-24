/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <gfragoso@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:55:53 by gfragoso          #+#    #+#             */
/*   Updated: 2024/03/22 13:58:03 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	33 -> CLIENT_MESSAGE x code
	1L << 17 -> mask for event 17 - close notif
*/
void	mlx_new(t_mlx *mlx, t_map *map)
{
	int	s;

	s = TILE_SIZE;
	mlx->map = map;
	mlx->move_count = 0;
	mlx->map->player.coins = 0;
	mlx->map->helper_elems = 0;
	mlx->ptr = mlx_init();
	mlx->wdw = mlx_new_window(mlx->ptr, map->w * s, map->h * s, "SO_LONG");
	mlx_key_hook(mlx->wdw, handle_keys, mlx);
	mlx_hook(mlx->wdw, 33, (1L << 17), &close_wdw, mlx);
}

int	main(int argc, char **argv)
{
	char	*p;
	int		fd;
	t_mlx	mlx;
	t_map	map;

	if (argc != 2)
		error_exit("Invalid number of arguments!\
		\n Usage: ./so_long <map file .ber>");
	p = ft_strrchr(argv[1], '.');
	if (!p || ft_strncmp(p, ".ber", 5))
		error_exit("Invalid file type! It must be a .ber file.");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_exit("There was an error trying to open the file.");
	map_load(fd, &map);
	mlx_new(&mlx, &map);
	print_map(mlx, map);
	mlx_loop(mlx.ptr);
	return (0);
}

// resize if fine as linux does not allow it
