/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:39:16 by alafdili          #+#    #+#             */
/*   Updated: 2024/04/01 11:46:14 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_wall(t_element cp, int y, int x)
{
	int			map_x;
	int			map_y;

	map_y = cp.map.map_y;
	map_x = cp.map.map_x;
	if (y == 0 || y == map_y - 1 || x == 0 || x == map_x - 1)
	{
		if (mlx_image_to_window(cp.mlx, cp.images[1], x * area, y * area) == -1)
			mlx_failure(cp, 1);
	}
	else
	{
		if (mlx_image_to_window(cp.mlx, cp.images[3], x * area, y * area) == -1)
			mlx_failure(cp, 1);
	}
}

void	put_image(t_element obj, mlx_t *mlx, int f)
{
	int	y;
	int	x;

	y = 0;
	while (obj.map.map[y])
	{
		x = 0;
		while (obj.map.map[y][x])
		{
			if (obj.map.map[y][x] == '1')
				put_wall(obj, y, x);
			else if (obj.map.map[y][x] == '0')
				f = mlx_image_to_window(mlx, obj.img.floor, x * area, y * area);
			else if (obj.map.map[y][x] == 'E')
				f = mlx_image_to_window(mlx, obj.img.cdoor, x * area, y * area);
			else if (obj.map.map[y][x] == 'P')
				f = mlx_image_to_window(mlx, obj.img.gamer, x * area, y * area);
			else if (obj.map.map[y][x] == 'C')
				f = mlx_image_to_window(mlx, obj.img.clt, x * area, y * area);
			if (f == -1)
				mlx_failure(obj, 1);
			x++;
		}
		y++;
	}
}
