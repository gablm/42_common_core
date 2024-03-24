/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <gfragoso@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:56:02 by gfragoso          #+#    #+#             */
/*   Updated: 2024/03/22 14:30:46 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_tiles(char **tiles, t_map *map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (tiles[i])
	{
		j = 0;
		while (tiles[i][j])
		{
			map->tiles[k] = (t_tile){i, j, tiles[i][j], 0};
			if (tiles[i][j] == 'C')
				map->total_coins += 1;
			if (tiles[i][j] == 'P')
			{
				map->n_p += 1;
				map->player.tile = map->tiles[k];
				map->tiles[k].type = '0';
			}
			j++;
			k++;
		}
		i++;
	}
}

int	map_len(char **map)
{
	int	i;

	if (!map)
		return (0);
	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	divide_map(char *str, t_map *map)
{
	char	**tiles;

	tiles = ft_split(str, '\n');
	if (!tiles)
		error_exit("There was a problem while allocating memory!");
	free(str);
	map->h = map_len(tiles);
	map->w = ft_strlen(*tiles);
	map->size = map->h * map->w;
	map->helper_elems = 0;
	map->total_coins = 0;
	map->n_e = 0;
	map->n_p = 0;
	if (map->size == 0)
		error_exit("Invalid map - Empty file");
	map->tiles = (t_tile *)malloc(sizeof(t_tile) * map->size);
	map->player.tile.x = -1;
	create_tiles(tiles, map);
	map_verify(map, tiles);
}

void	map_load(int fd, t_map *map)
{
	char	*line;
	char	*res;

	if (!map)
		return ;
	line = get_next_line(fd);
	res = ft_strdup("");
	while (line)
	{
		res = ft_strjoin(res, line);
		line = get_next_line(fd);
	}
	divide_map(res, map);
}
