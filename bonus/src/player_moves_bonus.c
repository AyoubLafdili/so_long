/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:35:54 by alafdili          #+#    #+#             */
/*   Updated: 2024/04/20 18:33:29 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	apply_move(t_element *var, int y, int x, mlx_t *mlx)
{
	mlx_image_t	*p_img;
	int			px;
	int			py;

	p_img = var->img[var->pdr];
	px = var->crd.px;
	py = var->crd.py;
	if (var->map.map[y][x] == 'C')
		--var->flags.c_flag;
	++var->crd.moves;
	string_to_window(var);
	if (mlx_image_to_window(mlx, var->img[FL], px * SIZE, py * SIZE) == -1
		|| mlx_image_to_window(mlx, p_img, x * SIZE, y * SIZE) == -1)
		mlx_failure(*var, "mlx func failed", 1);
	var->map.map[py][px] = '0';
	var->map.map[y][x] = 'P';
	var->crd.py = y;
	var->crd.px = x;
}

void	move_hundler(t_element *p, int y, int x)
{
	if (p->map.map[y][x] == '0' || p->map.map[y][x] == 'C')
		apply_move(p, y, x, p->mlx);
	else if (p->map.map[y][x] == 'E' && !check_collectible(p->map.map))
	{
		++p->crd.moves;
		string_to_window(p);
		ft_terminate(*p, "\033[1;32mYOU WIN\033[1;0m");
	}
	else if (p->map.map[y][x] == 'I')
		ft_terminate(*p, "\033[1;31mYOU LOSE\033[1;0m");
}

void	check_mov_action(t_element *action, char dir)
{
	if (dir == 'u')
	{
		action->pdr = PU;
		move_hundler(action, action->crd.py - 1, action->crd.px);
	}
	else if (dir == 'd')
	{
		action->pdr = P;
		move_hundler(action, action->crd.py + 1, action->crd.px);
	}
	else if (dir == 'r')
	{
		action->pdr = PR;
		move_hundler(action, action->crd.py, action->crd.px + 1);
	}
	else if (dir == 'l')
	{
		action->pdr = PL;
		move_hundler(action, action->crd.py, action->crd.px - 1);
	}
}

void	move_player(mlx_key_data_t keydata, void *param)
{
	t_element	*direction;

	direction = param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_failure(*direction, NULL, 3);
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
