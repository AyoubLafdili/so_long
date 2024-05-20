/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:34:16 by alafdili          #+#    #+#             */
/*   Updated: 2024/04/21 22:23:02 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	_free(char **to_free, char type)
{
	int	i;

	i = 0;
	if (!to_free)
		return ;
	if (type == 'm')
	{
		while (to_free[i])
		{
			free(to_free[i]);
			i++;
		}
		free(to_free);
	}
	else
	{
		if (*to_free)
			free(*to_free);
	}
}
