/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_failure_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:35:30 by alafdili          #+#    #+#             */
/*   Updated: 2024/04/08 22:33:47 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	mlx_failure(t_element to_free, char *error_msg, int flag)
{
	int	i;

	i = 0;
	while (i < 14)
	{
		if (to_free.img[i] == NULL || flag == 1 || flag == 3)
		{
			i = 0;
			while (i < 14)
			{
				if (to_free.img[i])
					mlx_delete_image(to_free.mlx, to_free.img[i]);
				if (to_free.txr[i])
					mlx_delete_texture(to_free.txr[i]);
				i++;
			}
			if (flag != 3 && to_free.mlx)
			{
				mlx_terminate(to_free.mlx);
				list_clear(to_free.head);
				err_alert(NULL, to_free.map.map, error_msg, '0');
			}
		}
		i++;
	}
}
