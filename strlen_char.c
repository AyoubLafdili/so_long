/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:03:09 by alafdili          #+#    #+#             */
/*   Updated: 2024/03/15 23:53:41 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	strlen_char(char *s)
{
	size_t	counter;

	counter = 0;
	while (s[counter] && s[counter] != '\n')
		counter++;
	return (counter);
}
