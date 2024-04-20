/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:03:09 by alafdili          #+#    #+#             */
/*   Updated: 2024/04/14 14:17:05 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	strlen_char(char *s)
{
	int	counter;

	counter = 0;
	while (s[counter] && s[counter] != '\n')
		counter++;
	return (counter);
}
