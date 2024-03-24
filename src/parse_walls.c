/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:03:35 by alafdili          #+#    #+#             */
/*   Updated: 2024/03/21 21:32:03 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_width(char **map, int y_len, int x_len)
{
	int	index;
	int	tmp;

	x_len -= 1;
	index = 1;
	tmp = 0;
	while (index < y_len - 1)
	{
		if (map[index][tmp] != '1')
			error_hundler(NULL, map, "Map Not Enclose By Walls\n", 'm');
		else if (tmp == 0 && map[index][tmp] == '1' && index + 1 == y_len - 1)
		{
			tmp = x_len;
			index = 1;
		}
		else
			index++;
	}
}

void	enclosed_walls(char *in_line_map, t_map *list)
{
	int	i;
	int	tmp;

	tmp = 0;
	i = 0;
	list->map = ft_split(in_line_map, '\n');
	if (!list->map)
		error_hundler(in_line_map, NULL, "Cannot Split Map", '0');
	while (list->map[tmp][i])
	{
		if (list->map[tmp][i] != '1')
			error_hundler(in_line_map, list->map, "Map Needs Walls!\n", 'm');
		else if (tmp == 0 && list->map[tmp][i] == '1' && !list->map[tmp][i + 1])
		{
			tmp = list->map_y - 1;
			i = 0;
		}
		else
			i++;
	}
	list->map_copy = ft_split(in_line_map, '\n');
	if (!list->map_copy)
		error_hundler(in_line_map, NULL, "Cannot Split Map Copy", '0');
	_free(&in_line_map, 'p');
	check_width(list->map, list->map_y, list->map_x);
}
