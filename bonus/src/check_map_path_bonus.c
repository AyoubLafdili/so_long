/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:33:36 by alafdili          #+#    #+#             */
/*   Updated: 2024/04/04 13:48:34 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_coordinate(char **map, char elem, int *x_elem, int *y_elem)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
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
	if (map[y][x] == 'V' || map[y][x] == '1' || map[y][x] == 'I')
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

void	check_valid_path(t_element *list)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	init_coordinate(list->map.map, 'P', &list->crd.px, &list->crd.py);
	init_coordinate(list->map.map, 'E', &list->crd.ex, &list->crd.ey);
	flood_fill(list->map.map_cp, list->crd.py, list->crd.px, list->map.map_y);
	while (list->map.map_cp[y])
	{
		x = 0;
		while (list->map.map_cp[y][x] && list->map.map_cp[y][x] != 'C'
			&& list->map.map_cp[y][x] != 'E')
			x++;
		if ((list->map.map_cp[y][x] == 'C' || list->map.map_cp[y][x] == 'E'))
		{
			_free(list->map.map_cp, 'm');
			err_alert(NULL, list->map.map, "Invalid Path to the Exit!", 'm');
		}
		y++;
	}
	_free(list->map.map_cp, 'm');
}
