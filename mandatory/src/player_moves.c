/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:23:09 by alafdili          #+#    #+#             */
/*   Updated: 2024/04/01 12:08:15 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	apply_move(t_element *var, int y, int x, int e[2])
{
	mlx_image_t	*odoor;
	mlx_image_t	*p_img;
	mlx_t		*mlx;
	int			px;
	int			py;

	p_img = var->images[var->pdr];
	odoor = var->img.odoor;
	mlx = var->mlx;
	px = var->crd.px;
	py = var->crd.py;
	ft_printf("moves: %d\n", ++var->crd.moves);
	if (var->map.map[y][x] == 'C' && --var->flags.c_flag == 0)
		if (mlx_image_to_window(mlx, odoor, e[0] * area, e[1] * area) == -1)
			mlx_failure(*var, 1);
	if (mlx_image_to_window(mlx, var->img.floor, px * area, py * area) == -1
		|| mlx_image_to_window(mlx, p_img, x * area, y * area) == -1)
		mlx_failure(*var, 1);
	var->map.map[py][px] = '0';
	var->map.map[y][x] = 'P';
	var->crd.py = y;
	var->crd.px = x;
}

void	move_hundler(t_element *p, int y, int x)
{
	int	_exit[2];

	_exit[0] = p->crd.ex;
	_exit[1] = p->crd.ey;
	if (p->map.map[y][x] == '0' || p->map.map[y][x] == 'C')
		apply_move(p, y, x, _exit);
	else if (p->map.map[y][x] == 'E' && !check_collectible(p->map.map))
	{
		_free(p->map.map, 'm');
		mlx_failure(*p, 3);
		mlx_terminate(p->mlx);
		ft_printf("moves: %d\nYOU WIN\n", ++p->crd.moves);
		exit(0);
	}
}

void	check_mov_action(t_element *action, char dir)
{
	if (dir == 'u')
	{
		action->pdr = 10;
		move_hundler(action, action->crd.py - 1, action->crd.px);
	}
	else if (dir == 'd')
	{
		action->pdr = 0;
		move_hundler(action, action->crd.py + 1, action->crd.px);
	}
	else if (dir == 'r')
	{
		action->pdr = 12;
		move_hundler(action, action->crd.py, action->crd.px + 1);
	}
	else if (dir == 'l')
	{
		action->pdr = 11;
		move_hundler(action, action->crd.py, action->crd.px - 1);
	}
}

void	move_player(mlx_key_data_t keydata, void *param)
{
	t_element	*direction;

	direction = param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_failure(*direction, 3);
		mlx_close_window(direction->mlx);
	}
	if ((keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		&& (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W))
		check_mov_action(direction, 'u');
	if ((keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		&& (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S))
		check_mov_action(direction, 'd');
	if ((keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		&& (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D))
		check_mov_action(direction, 'r');
	if ((keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		&& (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A))
		check_mov_action(direction, 'l');
}
