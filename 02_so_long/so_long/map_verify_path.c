/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verify_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <gfragoso@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:38:58 by gfragoso          #+#    #+#             */
/*   Updated: 2024/03/22 13:46:16 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	visitneighbour(t_map *map, int x, int y)
{
	t_tile	tile;

	tile = get_tile_at(map, x, y);
	if (tile.type == '1' || tile.visited)
		return ;
	map->tiles[x * map->w + y].visited = 1;
	if (tile.type != '0')
		map->helper_elems++;
	visitneighbour(map, x + 1, y);
	visitneighbour(map, x - 1, y);
	visitneighbour(map, x, y + 1);
	visitneighbour(map, x, y - 1);
}

int	map_verify_path(t_map *map)
{
	int	x;
	int	y;

	map->helper_elems = 0;
	x = map->player.tile.x;
	y = map->player.tile.y;
	visitneighbour(map, x, y);
	return (map->helper_elems != 1 + map->total_coins);
}
