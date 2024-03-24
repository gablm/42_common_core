/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <gfragoso@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:55:48 by gfragoso          #+#    #+#             */
/*   Updated: 2024/03/22 14:31:28 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	not_surrounded(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->w)
	{
		if (get_tile_at(map, 0, i).type != '1')
			return (1);
		if (get_tile_at(map, map->h - 1, i).type != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < map->h)
	{
		if (get_tile_at(map, i, 0).type != '1')
			return (1);
		if (get_tile_at(map, i, map->w - 1).type != '1')
			return (1);
		i++;
	}
	return (0);
}

int	contains_chars(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->size)
	{
		if (map->tiles[i].type == 'E')
			map->n_e++;
		i++;
	}
	return (map->n_e != 1 || map->total_coins < 1 || map->player.tile.x == -1);
}

int	free_char(char **split, int w)
{
	int	i;
	int	res;
	int	len;

	i = 0;
	res = 0;
	while (split[i])
	{
		len = ft_strlen(split[i]);
		if (len != w)
			res = 1;
		free(split[i]);
		i++;
	}
	free(split);
	return (res);
}

void	map_verify(t_map *map, char **split)
{
	if (free_char(split, map->w))
	{
		free(map->tiles);
		error_exit("Map must be rectangular.");
	}
	if (contains_chars(map) || map->n_p != 1)
	{
		free(map->tiles);
		error_exit("Map must contain at least one C, and only one E and P.");
	}
	if (not_surrounded(map))
	{
		free(map->tiles);
		error_exit("The map is not surrounded.");
	}
	map->helper_elems = 0;
	if (map_verify_path(map))
	{
		free(map->tiles);
		error_exit("It is impossible to complete the map.");
	}
}
