/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 22:42:29 by alafdili          #+#    #+#             */
/*   Updated: 2024/04/04 13:33:32 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	list_init(t_element *init)
{
	int	x;
	int	y;

	y = 0;
	while (init->map.map[y])
	{
		x = 0;
		while (init->map.map[y][x])
		{
			if (init->map.map[y][x] == 'I' && init->map.map[y][x + 1] != 'I'
				&& init->map.map[y][x + 1] != '\0')
			{
				add_to_list(&init->head, x, y);
				x++;
			}
			else
				x++;
		}
		y++;
	}
}