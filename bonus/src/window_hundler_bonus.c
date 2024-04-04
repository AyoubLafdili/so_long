/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_hundler_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:36:16 by alafdili          #+#    #+#             */
/*   Updated: 2024/04/04 13:44:36 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void back(t_element *params, t_enemy *_enemy)
{
	int ix;
	int iy;

	ix = _enemy->x;
	iy = _enemy->y;
	if (params->map.map[iy][ix - 1] == '1' || params->map.map[iy][ix - 1] == 'I'
		|| params->map.map[iy][ix - 1] == 'E' || params->map.map[iy][ix - 1] == 'C')
		return ;
	else if (params->map.map[iy][ix - 1] == 'P')
	{
		list_clear(params->head);
		_free(params->map.map, 'm');
		mlx_failure(*params, 3);
		mlx_terminate(params->mlx);
		ft_printf("\033[1;31mYOU LOSE\n\033[1;0m");
		exit(0);
	}
	else if (params->map.map[iy][ix - 1] == '0')
	{
		mlx_image_to_window(params->mlx, params->images[4], ix * area, iy * area);
		mlx_image_to_window(params->mlx, params->images[13], (ix - 1) * area, iy * area);
		params->map.map[iy][ix] = '0';
		params->map.map[iy][ix - 1] = 'I';
		_enemy->x--;
	}
}

void enemy_action(t_element *params, t_enemy *_enemy)
{
	int ix;
	int iy;

	ix = _enemy->x;
	iy = _enemy->y;
	if (params->map.map[iy][ix + 1] == '1' || params->map.map[iy][ix + 1] == 'I'
		|| params->map.map[iy][ix + 1] == 'E' || params->map.map[iy][ix + 1] == 'C')
		return ;
	else if (params->map.map[iy][ix + 1] == 'P')
	{
		list_clear(params->head);
		_free(params->map.map, 'm');
		mlx_failure(*params, 3);
		mlx_terminate(params->mlx);
		ft_printf("\033[1;31mYOU LOSE\n\033[1;0m");
		exit(0);
	}
	else if (params->map.map[iy][ix + 1] == '0')
	{
		mlx_image_to_window(params->mlx, params->images[4], ix * area, iy * area);
		mlx_image_to_window(params->mlx, params->images[13], (ix + 1) * area, iy * area);
		params->map.map[iy][ix] = '0';
		params->map.map[iy][ix + 1] = 'I';
		_enemy->x++;
	}
}
void move_enemy(void *param)
{
	t_enemy	*first;
	t_element *var;
	static int i = 0;
	static int timer = 0;

	var = param;
	first = var->head;
	while (timer % 50 == 0 && first != NULL)
	{
		if (i % 2 == 0)
			enemy_action(var, first);
		else
			back(var, first);
		if (i == 0 && first->next == NULL)
			i = 1;
		else if (i == 1 && first->next == NULL)
			i = 0;
		first = first->next;
	}
	timer++;
}

void	animate_door(void *param)
{
	static int	i = 0;
	t_element	*vars;
	int			ex;
	int			ey;

	vars = param;
	ex = vars->crd.ex * area;
	ey = vars->crd.ey * area;
	if (vars->flags.c_flag == 0 && vars->counter % 10 == 0 && i < 3)
	{
		if (mlx_image_to_window(vars->mlx, vars->images[i + 7], ex, ey) == -1)
			mlx_failure(*vars, 1);
		i++;
	}
	vars->counter++;
}

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
	list->mlx = mlx_init(x * area, y * area, "so_long", false);
	if (!list->mlx)
		err_alert(NULL, list->map.map, "Window Set Up Eroor", '0');
	init_obj(list);
	put_image(list, list->mlx, 0);
	mlx_put_string(list->mlx, "MOVES: 0", 50, 13);
	mlx_key_hook(list->mlx, move_player, list);
	mlx_loop_hook(list->mlx, animate_door, list);
	mlx_loop_hook(list->mlx, move_enemy, list);
	mlx_close_hook(list->mlx, close_callback, list);
	mlx_loop(list->mlx);
}
