/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:38:40 by alafdili          #+#    #+#             */
/*   Updated: 2024/04/01 11:50:34 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_arr_init(t_element *local_img)
{
	local_img->images[0] = local_img->img.gamer;
	local_img->images[1] = local_img->img.c_wall;
	local_img->images[2] = local_img->img.wall1;
	local_img->images[3] = local_img->img.wall2;
	local_img->images[4] = local_img->img.floor;
	local_img->images[5] = local_img->img.clt;
	local_img->images[6] = local_img->img.cdoor;
	local_img->images[7] = local_img->img.door1;
	local_img->images[8] = local_img->img.door2;
	local_img->images[9] = local_img->img.odoor;
	local_img->images[10] = local_img->img.p_up;
	local_img->images[11] = local_img->img.p_left;
	local_img->images[12] = local_img->img._rigth;
}

void	txr_arr_init(t_element *local_img)
{
	local_img->texture[0] = local_img->txr.player;
	local_img->texture[1] = local_img->txr.c_wall;
	local_img->texture[2] = local_img->txr.nwall1;
	local_img->texture[3] = local_img->txr.nwall2;
	local_img->texture[4] = local_img->txr.floor;
	local_img->texture[5] = local_img->txr.collect;
	local_img->texture[6] = local_img->txr.cdoor;
	local_img->texture[7] = local_img->txr.door1;
	local_img->texture[8] = local_img->txr.door2;
	local_img->texture[9] = local_img->txr.odoor;
	local_img->texture[10] = local_img->txr.p_up;
	local_img->texture[11] = local_img->txr.p_left;
	local_img->texture[12] = local_img->txr._rigth;
}

void	img_init(t_element *images)
{
	images->img.gamer = mlx_texture_to_image(images->mlx, images->txr.player);
	images->img.c_wall = mlx_texture_to_image(images->mlx, images->txr.c_wall);
	images->img.wall1 = mlx_texture_to_image(images->mlx, images->txr.nwall1);
	images->img.wall2 = mlx_texture_to_image(images->mlx, images->txr.nwall2);
	images->img.floor = mlx_texture_to_image(images->mlx, images->txr.floor);
	images->img.clt = mlx_texture_to_image(images->mlx, images->txr.collect);
	images->img.odoor = mlx_texture_to_image(images->mlx, images->txr.odoor);
	images->img.cdoor = mlx_texture_to_image(images->mlx, images->txr.cdoor);
	images->img.door1 = mlx_texture_to_image(images->mlx, images->txr.door1);
	images->img.door2 = mlx_texture_to_image(images->mlx, images->txr.door2);
	images->img.p_up = mlx_texture_to_image(images->mlx, images->txr.p_up);
	images->img.p_left = mlx_texture_to_image(images->mlx, images->txr.p_left);
	images->img._rigth = mlx_texture_to_image(images->mlx, images->txr._rigth);
}

void	txr_init(t_element *objects)
{
	objects->txr.player = mlx_load_png(player_png);
	objects->txr.c_wall = mlx_load_png(corner_wall);
	objects->txr.nwall1 = mlx_load_png(nested1);
	objects->txr.nwall2 = mlx_load_png(nested2);
	objects->txr.floor = mlx_load_png(floor_png);
	objects->txr.collect = mlx_load_png(collectible);
	objects->txr.odoor = mlx_load_png(opened_door);
	objects->txr.cdoor = mlx_load_png(closed_door);
	objects->txr.door1 = mlx_load_png(stage_one);
	objects->txr.door2 = mlx_load_png(stage_two);
	objects->txr.p_up = mlx_load_png(player_front);
	objects->txr.p_left = mlx_load_png(player_left);
	objects->txr._rigth = mlx_load_png(player_rigth);
}

void	init_obj(t_element *list)
{
	txr_init(list);
	txr_arr_init(list);
	img_init(list);
	img_arr_init(list);
	mlx_failure(*list, 0);
}
