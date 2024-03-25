/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:57:28 by alafdili          #+#    #+#             */
/*   Updated: 2024/03/25 18:08:40 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void img_arr_init(t_element *local_img)
{
	local_img->images[0] = local_img->img.gamer;
	local_img->images[1] = local_img->img.c_wall;
	local_img->images[2] = local_img->img.wall1;
	local_img->images[3] = local_img->img.wall2;
	local_img->images[4] = local_img->img.floor;
	local_img->images[5] = local_img->img.clt;
	local_img->images[6] = local_img->img.odoor;
	local_img->images[7] = local_img->img.cdoor;
} 

void txr_arr_init(t_element *local_img)
{
	local_img->texture[0] = local_img->txr.player;
	local_img->texture[1] = local_img->txr.c_wall;
	local_img->texture[2] = local_img->txr.nwall1;
	local_img->texture[3] = local_img->txr.nwall2;
	local_img->texture[4] = local_img->txr.floor;
	local_img->texture[5] = local_img->txr.collect;
	local_img->texture[6] = local_img->txr.odoor;
	local_img->texture[7] = local_img->txr.cdoor;
}                        

void image_init(t_element *images)
{
	images->img.gamer = mlx_texture_to_image(images->mlx, images->txr.player);
	images->img.c_wall = mlx_texture_to_image(images->mlx, images->txr.c_wall);
	images->img.wall1 = mlx_texture_to_image(images->mlx, images->txr.nwall1);
	images->img.wall2 = mlx_texture_to_image(images->mlx, images->txr.nwall2);
	images->img.floor = mlx_texture_to_image(images->mlx, images->txr.floor);
	images->img.clt = mlx_texture_to_image(images->mlx, images->txr.collect);
	images->img.odoor = mlx_texture_to_image(images->mlx, images->txr.odoor);
	images->img.cdoor = mlx_texture_to_image(images->mlx, images->txr.cdoor);
}
                                                                                                                                                                                                                                                                                                   
void texture_init(t_element *objects)
{
	objects->txr.player = mlx_load_png(player_png);
	objects->txr.c_wall = mlx_load_png(corner_wall);
	objects->txr.nwall1 = mlx_load_png(nested1);
	objects->txr.nwall2 = mlx_load_png(nested2);
	objects->txr.floor = mlx_load_png(floor_png);
	objects->txr.collect = mlx_load_png(collectible);
	objects->txr.odoor = mlx_load_png(opened_door);
	objects->txr.cdoor = mlx_load_png(closed_door);
}

void init_obj(t_element *list)
{
	texture_init(list);
	image_init(list);
	txr_arr_init(list);
	img_arr_init(list);
	failure_hundler(*list, 0);
}