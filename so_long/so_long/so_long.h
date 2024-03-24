/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <gfragoso@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:35:16 by gfragoso          #+#    #+#             */
/*   Updated: 2024/03/18 19:12:10 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>

# define TILE_SIZE 64

typedef struct s_tile
{
	int		x;
	int		y;
	char	type;
	int		visited;
}	t_tile;

typedef struct s_player
{
	int		coins;
	t_tile	tile;
}	t_player;

typedef struct s_map
{
	t_player	player;
	int			total_coins;
	int			helper_elems;
	int			n_p;
	int			n_e;
	t_tile		*tiles;
	int			size;
	int			w;
	int			h;
}	t_map;

typedef struct s_mlx
{
	void	*ptr;
	void	*wdw;
	t_map	*map;
	int		move_count;
}	t_mlx;

void	error_exit(char *str);
int		close_wdw(t_mlx *mlx);

t_tile	get_tile_at(t_map *map, int x, int y);
int		handle_keys(int keycode, t_mlx *mlx);
void	print_map(t_mlx mlx, t_map map);

int		map_verify_path(t_map *map);
void	map_load(int fd, t_map *map);
void	map_verify(t_map *map, char **split);
void	divide_map(char *str, t_map *map);

// gnl
char	*get_next_line(int fd);

#endif
