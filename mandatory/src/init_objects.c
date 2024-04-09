/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:38:40 by alafdili          #+#    #+#             */
/*   Updated: 2024/04/09 03:41:10 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	first_check(t_element check_txr)
{
	int	c;

	c = 0;
	while (c < 12)
	{
		if (check_txr.txr[c] == NULL)
		{
			c = 0;
			while (c < 14)
			{
				mlx_delete_texture(check_txr.txr[c]);
				c++;
			}
			mlx_terminate(check_txr.mlx);
			err_alert(NULL, check_txr.map.map, "mlx load failed", '0');
		}
		c++;
	}
}

void	img_init(t_element *img)
{
	img->img[P] = mlx_texture_to_image(img->mlx, img->txr[P]);
	img->img[PU] = mlx_texture_to_image(img->mlx, img->txr[PU]);
	img->img[PL] = mlx_texture_to_image(img->mlx, img->txr[PL]);
	img->img[PR] = mlx_texture_to_image(img->mlx, img->txr[PR]);
	img->img[OD] = mlx_texture_to_image(img->mlx, img->txr[OD]);
	img->img[CD] = mlx_texture_to_image(img->mlx, img->txr[CD]);
	img->img[S1] = mlx_texture_to_image(img->mlx, img->txr[S1]);
	img->img[S2] = mlx_texture_to_image(img->mlx, img->txr[S2]);
	img->img[CW] = mlx_texture_to_image(img->mlx, img->txr[CW]);
	img->img[NW] = mlx_texture_to_image(img->mlx, img->txr[NW]);
	img->img[FL] = mlx_texture_to_image(img->mlx, img->txr[FL]);
	img->img[C] = mlx_texture_to_image(img->mlx, img->txr[C]);
}

void	txr_init(t_element *objects)
{
	objects->txr[P] = mlx_load_png(PLAYER);
	objects->txr[PU] = mlx_load_png(PLAYER_UP);
	objects->txr[PL] = mlx_load_png(PLAYER_LEFT);
	objects->txr[PR] = mlx_load_png(PLAYER_RIGHT);
	objects->txr[OD] = mlx_load_png(OPENED_DOOR);
	objects->txr[CD] = mlx_load_png(CLOSED_DOOR);
	objects->txr[S1] = mlx_load_png(STAGE_ONE);
	objects->txr[S2] = mlx_load_png(STAGE_TWO);
	objects->txr[CW] = mlx_load_png(CORNER_WALL);
	objects->txr[NW] = mlx_load_png(NESTED);
	objects->txr[FL] = mlx_load_png(FLOOR);
	objects->txr[C] = mlx_load_png(COLLECTEBLE);
}

void	init_obj(t_element *list)
{
	txr_init(list);
	first_check(*list);
	img_init(list);
	mlx_failure(*list, 0);
}
