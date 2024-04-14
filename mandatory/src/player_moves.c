/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:23:09 by alafdili          #+#    #+#             */
/*   Updated: 2024/04/09 03:43:19 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	apply_move(t_element *var, int y, int x, int e[2])
{
	mlx_image_t	*odoor;
	mlx_t		*mlx;
	int			px;
	int			py;

	odoor = var->img[OD];
	mlx = var->mlx;
	px = var->crd.px;
	py = var->crd.py;
	ft_printf("\033[1;33mmoves: %d\n\033[1;m", ++var->crd.moves);
	if (var->map.map[y][x] == 'C' && --var->flags.c_flag == 0)
		if (mlx_image_to_window(mlx, odoor, e[0] * SIZE, e[1] * SIZE) == -1)
			mlx_failure(*var, 1);
	if (mlx_image_to_window(mlx, var->img[FL], px * SIZE, py * SIZE) == -1
		|| mlx_image_to_window(mlx, var->img[P], x * SIZE, y * SIZE) == -1)
		mlx_failure(*var, 1);
	var->map.map[py][px] = '0';
	var->map.map[y][x] = 'P';
	var->crd.py = y;
	var->crd.px = x;
}

void	move_hundler(t_element *p, int y, int x)
{
	if (p->map.map[y][x] == '0' || p->map.map[y][x] == 'C')
		apply_move(p, y, x, (int []){p->crd.ex, p->crd.ey});
	else if (p->map.map[y][x] == 'E' && !check_collectible(p->map.map))
	{
		_free(p->map.map, 'm');
		mlx_failure(*p, 3);
		mlx_terminate(p->mlx);
		ft_printf("\033[1;33mmoves: %d\n\033[1;m", ++p->crd.moves);
		ft_printf("\033[1;32mYOU WIN\n\033[1;m");
		exit(0);
	}
}

void	check_mov_action(t_element *action, char dir)
{
	if (dir == 'u')
		move_hundler(action, action->crd.py - 1, action->crd.px);
	else if (dir == 'd')
		move_hundler(action, action->crd.py + 1, action->crd.px);
	else if (dir == 'r')
		move_hundler(action, action->crd.py, action->crd.px + 1);
	else if (dir == 'l')
		move_hundler(action, action->crd.py, action->crd.px - 1);
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
