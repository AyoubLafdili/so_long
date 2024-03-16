/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:07:48 by alafdili          #+#    #+#             */
/*   Updated: 2024/03/16 00:34:22 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_coordinate(char **map, char elem, int *x_elem, int *y_elem)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == elem)
			{
				*x_elem = x;
				*y_elem = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	flood_fill(char **map, int y, int x, int map_size)
{
	if (y < 0 || y >= map_size || x < 0
		|| (size_t)x >= strlen_char(map[0]) || map[y][x] == 'V'
			|| map[y][x] == '1')
		return ;
	if (map[y][x] == 'E')
		map[y][x] = '1';
	else if (map[y][x] != '1')
	{
		map[y][x] = 'V';
		flood_fill(map, y - 1, x, map_size);
		flood_fill(map, y + 1, x, map_size);
		flood_fill(map, y, x - 1, map_size);
		flood_fill(map, y, x + 1, map_size);
	}
}

void	check_valid_path(t_flags list)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	init_coordinate(list.map, 'P', &list.px, &list.py);
	init_coordinate(list.map, 'E', &list.ex, &list.ey);
	flood_fill(list.map_copy, list.py, list.px, list.map_size);
	while (list.map_copy[y])
	{
		x = 0;
		while (list.map_copy[y][x] && list.map_copy[y][x] != 'C'
			&& list.map_copy[y][x] != 'E')
			x++;
		if ((list.map_copy[y][x] == 'C' || list.map_copy[y][x] == 'E')
			&& list.map_copy[y][x])
		{
			_free(list.map, 'm');
			_free(list.map_copy, 'm');
			error_hundler(NULL, NULL, "Invalid Map Path to the Exit!\n", '0');
		}
		y++;
	}
}
