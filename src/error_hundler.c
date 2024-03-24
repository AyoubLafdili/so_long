/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_hundler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:06:16 by alafdili          #+#    #+#             */
/*   Updated: 2024/03/23 18:24:09 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_hundler(char *str, char **other, char *msg, char flag)
{
	if (str)
		_free(&str, 'p');
	if (flag == 'm')
	{
		if (other)
			_free(other, 'm');
	}
	if (flag == 'p')
	{
		if (*other)
			_free(other, 'p');
	}
	write(1, "Error\n", 6);
	write(1, msg, ft_strlen(msg));
	exit(1);
}
