/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:07:08 by alafdili          #+#    #+#             */
/*   Updated: 2024/03/16 00:43:01 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
