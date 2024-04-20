/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:36:04 by alafdili          #+#    #+#             */
/*   Updated: 2024/04/20 12:29:52 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	list_clear(t_enemy *list)
{
	t_enemy	*tmp;

	if (!list)
		return ;
	while (list != NULL)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}
