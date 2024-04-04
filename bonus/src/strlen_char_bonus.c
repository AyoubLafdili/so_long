/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_char_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:36:08 by alafdili          #+#    #+#             */
/*   Updated: 2024/04/01 17:35:09 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

size_t	strlen_char(char *s)
{
	size_t	counter;

	counter = 0;
	while (s[counter] && s[counter] != '\n')
		counter++;
	return (counter);
}
