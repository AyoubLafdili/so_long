/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_failure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:28:06 by alafdili          #+#    #+#             */
/*   Updated: 2024/04/20 16:59:44 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_failure(t_element to_free, int flag)
{
	int	i;

	i = 0;
	while (i < 12)
	{
		if (to_free.img[i] == NULL || flag == 1 || flag == 3)
		{
			i = 0;
			while (i < 12)
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
				err_alert(NULL, to_free.map.map, "mlx func failed", '0');
			}
		}
		i++;
	}
}
