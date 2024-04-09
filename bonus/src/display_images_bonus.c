/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_images_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:33:49 by alafdili          #+#    #+#             */
/*   Updated: 2024/04/09 03:43:19 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_wall(t_element cp, int y, int x)
{
	int			map_x;
	int			map_y;

	map_y = cp.map.map_y;
	map_x = cp.map.map_x;
	if (y == 0 || y == map_y - 1 || x == 0 || x == map_x - 1)
	{
		if (mlx_image_to_window(cp.mlx, cp.img[CW], x * SIZE, y * SIZE) == -1)
			mlx_failure(cp, "mlx func failed", 1);
	}
	else
	{
		if (mlx_image_to_window(cp.mlx, cp.img[NW], x * SIZE, y * SIZE) == -1)
			mlx_failure(cp, "mlx func failed", 1);
	}
}

int	check_to_apply(t_element obj, int y, int x)
{
	mlx_t	*mlx;
	int		f;
	int		win_x;
	int		win_y;

	f = 0;
	win_x = x * SIZE;
	win_y = y * SIZE;
	mlx = obj.mlx;
	if (obj.map.map[y][x] == '1')
		put_wall(obj, y, x);
	else if (obj.map.map[y][x] == '0')
		f = mlx_image_to_window(mlx, obj.img[FL], win_x, win_y);
	else if (obj.map.map[y][x] == 'E')
		f = mlx_image_to_window(mlx, obj.img[CD], win_x, win_y);
	else if (obj.map.map[y][x] == 'P')
		f = mlx_image_to_window(mlx, obj.img[P], win_x, win_y);
	else if (obj.map.map[y][x] == 'C')
		f = mlx_image_to_window(mlx, obj.img[C], win_x, win_y);
	else if (obj.map.map[y][x] == 'I')
		f = mlx_image_to_window(mlx, obj.img[I], win_x, win_y);
	return (f);
}

void	put_image(t_element obj)
{
	int	y;
	int	x;

	y = 0;
	while (obj.map.map[y])
	{
		x = 0;
		while (obj.map.map[y][x])
		{
			if (check_to_apply(obj, y, x) == -1)
				mlx_failure(obj, "mlx func failed", 1);
			x++;
		}
		y++;
	}
}
