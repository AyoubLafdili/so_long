/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_walls_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:35:47 by alafdili          #+#    #+#             */
/*   Updated: 2024/04/09 00:30:46 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_width(t_element *var, char *merged, int y_len, int x_len)
{
	int	index;
	int	tmp;

	index = 1;
	tmp = 0;
	while (index < y_len - 1)
	{
		if (var->map.map[index][tmp] != '1')
			err_alert(merged, var->map.map, "Map Not Enclose By Walls", 'm');
		else if (tmp == 0 && var->map.map[index][tmp] == '1'
			&& index + 1 == y_len - 1)
		{
			tmp = x_len;
			index = 1;
		}
		else
			index++;
	}
	var->map.map_cp = ft_split(merged, '\n');
	if (!var->map.map_cp)
		err_alert(merged, var->map.map, "Cannot Split Map Copy", 'm');
}

void	enclosed_walls(char *merged, t_element *var)
{
	int	i;
	int	tmp;

	tmp = 0;
	i = 0;
	var->map.map = ft_split(merged, '\n');
	if (!var->map.map)
		err_alert(merged, NULL, "Cannot Split Map", '0');
	while (var->map.map[tmp][i])
	{
		if (var->map.map[tmp][i] != '1')
			err_alert(merged, var->map.map, "Map Needs Walls!", 'm');
		else if (tmp == 0 && var->map.map[tmp][i] == '1'
			&& !var->map.map[tmp][i + 1])
		{
			tmp = var->map.map_y - 1;
			i = 0;
		}
		else
			i++;
	}
	check_width(var, merged, var->map.map_y, var->map.map_x - 1);
	_free(&merged, 'p');
}
