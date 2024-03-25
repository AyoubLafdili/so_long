/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   failure_hundler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:15:23 by alafdili          #+#    #+#             */
/*   Updated: 2024/03/25 18:37:18 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	failure_hundler(t_element to_free, int flag)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		if (to_free.texture[i] == NULL || to_free.images[i] == NULL
			|| flag == 1 || flag == 3)
		{
			i = 0;
			while (i < 7)
			{
				if (to_free.images[i])
					free(to_free.images[i]);
				free(to_free.texture[i]);
				i++;
			}
			if (flag != 3)
				error_hundler(NULL, to_free.map.map, "mlx func failed", '0');
			i = 0;
		}
		i++;
	}
}
