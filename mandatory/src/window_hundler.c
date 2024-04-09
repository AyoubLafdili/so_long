/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_hundler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:40:52 by alafdili          #+#    #+#             */
/*   Updated: 2024/04/09 03:43:19 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_callback(void *param)
{
	t_element	*close;

	close = param;
	mlx_failure(*close, 3);
}

void	window_hundeler(t_element *list)
{
	int	y;
	int	x;

	x = list->map.map_x;
	y = list->map.map_y;
	list->mlx = mlx_init(x * SIZE, y * SIZE, "so_long", false);
	if (!list->mlx)
		err_alert(NULL, list->map.map, "Window Set Up Eroor", '0');
	init_obj(list);
	put_image(*list, list->mlx, 0);
	mlx_key_hook(list->mlx, move_player, list);
	mlx_close_hook(list->mlx, close_callback, list);
	mlx_loop(list->mlx);
}
