/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:01:36 by alafdili          #+#    #+#             */
/*   Updated: 2024/03/23 23:54:32 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void	check_map_name(char *map_name)
{
	int	name_len;

	name_len = ft_strlen(map_name);
	if (name_len > 4)
	{
		if (!ft_strncmp(&map_name[name_len - 4], ".ber", 4))
			return ;
		else
			error_hundler(NULL, NULL, "Invalid Extension!\n", '0');
	}
	else
		error_hundler(NULL, NULL, "File Name Not Recognized!\n", '0');
}

int check_collectible(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\n' && map[y][x])
		{
			if (map[y][x] == 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
void apply_move(t_element *p, int y, int x)
{
	int px;
	int py;

	px = p->crd.px;
	py = p->crd.py;
	if (p->map.map[y][x] == '0' || p->map.map[y][x] == 'C')
	{
		mlx_image_to_window(p->mlx, p->img.floor, px * pixels, py * pixels);
		mlx_image_to_window(p->mlx, p->img.player, x * pixels, y * pixels);
		p->map.map[py][px] = '0';
		p->map.map[y][x] = 'P';
		p->crd.py = y;
		p->crd.px = x;
	}
	else if (p->map.map[y][x] == 'E' && !check_collectible(p->map.map))
	{
		mlx_terminate(p->mlx);
		_free(p->map.map, 'm');
		write(0, "YOU WIN!\n", 9);
		exit(0);
	}
	else if (p->map.map[y][x] == 'E' && check_collectible(p->map.map))
		return ;
	else
		return ;
}

void  check_mov_action(t_element *action, char dir)
{
	if (dir == 'u')
		apply_move(action, action->crd.py - 1, action->crd.px);
	else if (dir == 'd')
		apply_move(action, action->crd.py + 1, action->crd.px);
	else if (dir == 'r')
		apply_move(action, action->crd.py, action->crd.px + 1);
	else if (dir == 'l')
		apply_move(action, action->crd.py, action->crd.px - 1);
}

void	move_player(mlx_key_data_t keydata, void* param)
{
	t_element *direction;

	direction = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(direction->mlx);
	if ((keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		&& (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W))
		check_mov_action(direction, 'u');
	if ((keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		&& (keydata.key == MLX_KEY_DOWN  || keydata.key == MLX_KEY_S))
		check_mov_action(direction, 'd');
	if ((keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		&& (keydata.key == MLX_KEY_RIGHT  || keydata.key == MLX_KEY_D))
		check_mov_action(direction, 'r');
	if ((keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		&& (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A))
		check_mov_action(direction, 'l');
}
void	put_wall(t_element c_obj, int y, int x)
{
	int map_x;
	int map_y;

	map_y = c_obj.map.map_y;
	map_x = c_obj.map.map_x;
	if (y == 0 || y == map_y - 1 || x == 0 || x == map_x - 1)
	{
		if(mlx_image_to_window(c_obj.mlx, c_obj.img.c_wall, x * 50, y * 50) == -1)
			failure_hundler(c_obj, 1);
		
	}
	else
	{
		if (mlx_image_to_window(c_obj.mlx, c_obj.img.c_wall, x * 50, y * 50) == -1)
			failure_hundler(c_obj, 1);
	}
}

void	put_image(t_element obj, int fail)
{
	int	y;
	int x;

	y = 0;
	while (obj.map.map[y])
	{
		x = 0;
		while (obj.map.map[y][x] != '\n')
		{
			if (obj.map.map[y][x] == '1')
				put_wall(obj, y, x);
			else if (obj.map.map[y][x] == '0')
				fail = mlx_image_to_window(obj.mlx, obj.img.floor, x * 50, y * 50);
			else if (obj.map.map[y][x] == 'E')
				fail = mlx_image_to_window(obj.mlx, obj.img.c_door, x * 50, y * 50);
			else if (obj.map.map[y][x] == 'P')
				fail = mlx_image_to_window(obj.mlx, obj.img.player, x * 50, y * 50);
			else if (obj.map.map[y][x] == 'C')
				fail = mlx_image_to_window(obj.mlx, obj.img.clt, x * 50, y * 50);
			x++;
		}
		if(fail == -1)
			failure_hundler(obj, 1);
		y++;
	}
}

void	window_hundeler(t_element *list)
{
	int	y;
	int	x;

	x = list->map.map_x;
	y = list->map.map_y;
	list->mlx = mlx_init(x * pixels, y * pixels, "so_long", false);
	if (!list->mlx)
		error_hundler(NULL, list->map.map, "failed to initialize the window\n", '0');
	init_obj(list);
	put_image(*list, 0);
	mlx_key_hook(list->mlx, move_player, list);
	mlx_loop(list->mlx);
}

int	main(int argc, char *argv[])
{
	t_element	list;
	char		*joined_lines;

	ft_memset(&list, 0, sizeof(t_element));
	if (argc > 2 || argc == 1)
		error_hundler(NULL, NULL, "Review Your Input Arguments!\n", '0');
	check_map_name(argv[1]);
	joined_lines = map_parsing(argv[1], &list);
	enclosed_walls(joined_lines, &list.map);
	check_valid_path(&list);
	window_hundeler(&list);
	_free(list.map.map, 'm');
	mlx_terminate(list.mlx);
	return (0);
}
