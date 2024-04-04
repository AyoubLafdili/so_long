/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_failure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:28:06 by alafdili          #+#    #+#             */
/*   Updated: 2024/04/01 12:20:51 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_failure(t_element to_free, int flag)
{
	int	i;

	i = 0;
	while (i < 13)
	{
		if (to_free.texture[i] == NULL || to_free.images[i] == NULL
			|| flag == 1 || flag == 3)
		{
			i = 0;
			while (i < 13)
			{
				if (to_free.images[i])
					mlx_delete_image(to_free.mlx, to_free.images[i]);
				mlx_delete_texture(to_free.texture[i]);
				i++;
			}
			if (flag != 3)
			{
				if (to_free.mlx)
					mlx_terminate(to_free.mlx);
				err_alert(NULL, to_free.map.map, "mlx func failed", '0');
			}
		}
		i++;
	}
}
