/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:28:40 by alafdili          #+#    #+#             */
/*   Updated: 2024/04/09 00:34:23 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	add_to_list(t_enemy **head, int ix, int iy)
{
	t_enemy	*new_node;

	new_node = NULL;
	new_node = malloc(sizeof(t_enemy));
	if (!new_node)
		return (list_clear(*head), 1);
	new_node->x = ix;
	new_node->y = iy;
	new_node->next = *head;
	*head = new_node;
	return (0);
}
