/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_hundler_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:36:16 by alafdili          #+#    #+#             */
/*   Updated: 2024/04/22 14:28:09 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	take_action(t_element *vars, t_enemy *_enemy, int dir, mlx_t *mlx)
{
	int	iy;
	int	win_x;
	int	win_y;

	iy = _enemy->y;
	win_x = _enemy->x * SIZE;
	win_y = iy * SIZE;
	if (vars->map.map[iy][dir] == '1' || vars->map.map[iy][dir] == 'E'
		|| vars->map.map[iy][dir] == 'C')
		return ;
	else if (vars->map.map[iy][dir] == 'P')
		ft_terminate(*vars, "\033[1;41mYOU LOSE\033[1;0m");
	else if (vars->map.map[iy][dir] == '0')
	{
		if (mlx_image_to_window(mlx, vars->img[FL], win_x, win_y) == -1)
			mlx_failure(*vars, "mlx func failed", 1);
		if (mlx_image_to_window(mlx, vars->img[I], dir * SIZE, win_y) == -1)
			mlx_failure(*vars, "mlx func failed", 1);
		vars->map.map[iy][_enemy->x] = '0';
		vars->map.map[iy][dir] = 'I';
		if (dir < _enemy->x)
			_enemy->x--;
		else
			_enemy->x++;
	}
}

void	move_enemy(void *param)
{
	t_enemy		*first;
	t_element	*var;
	static int	i;
	static int	counter;

	var = param;
	first = var->head;
	while (counter % 50 == 0 && first != NULL)
	{
		if (i == 0)
			take_action(var, first, first->x + 1, var->mlx);
		else
			take_action(var, first, first->x - 1, var->mlx);
		if (i == 0 && first->next == NULL)
			i = 1;
		else if (i == 1 && first->next == NULL)
			i = 0;
		first = first->next;
	}
	counter++;
}

void	animate_door(void *param)
{
	static int	i = 0;
	static int	counter = 0;
	t_element	*vars;
	int			ex;
	int			ey;

	vars = param;
	ex = vars->crd.ex * SIZE;
	ey = vars->crd.ey * SIZE;
	if (vars->flags.c_flag == 0 && counter % 10 == 0 && i < 3)
	{
		if (mlx_image_to_window(vars->mlx, vars->img[i + 5], ex, ey) == -1)
			mlx_failure(*vars, "mlx func failed", 1);
		i++;
	}
	counter++;
}

void	close_callback(void *param)
{
	t_element	*close;

	close = param;
	mlx_failure(*close, NULL, 3);
}

void	window_hundeler(t_element *vars)
{
	int	y;
	int	x;

	x = vars->map.map_x;
	y = vars->map.map_y;
	vars->mlx = mlx_init(x * SIZE, y * SIZE, "so_long", false);
	if (!vars->mlx)
	{
		list_clear(vars->head);
		err_alert(NULL, vars->map.map, "Window Set Up Eroor", '0');
	}
	init_obj(vars);
	put_image(*vars);
	string_to_window(vars);
	mlx_key_hook(vars->mlx, move_player, vars);
	mlx_loop_hook(vars->mlx, animate_door, vars);
	mlx_loop_hook(vars->mlx, move_enemy, vars);
	mlx_close_hook(vars->mlx, close_callback, vars);
	mlx_loop(vars->mlx);
}
