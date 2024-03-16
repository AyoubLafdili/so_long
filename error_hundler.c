/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_hundler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:06:16 by alafdili          #+#    #+#             */
/*   Updated: 2024/03/16 00:43:43 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_hundler(char *str, char **in_line_map, char *msg, char flag)
{
	if (str)
		_free(&str, 'p');
	if (flag == 'm')
	{
		if (in_line_map)
			_free(in_line_map, 'm');
	}
	if (flag == 'p')
	{
		if (*in_line_map)
			_free(in_line_map, 'p');
	}
	write(1, "Error\n", 6);
	write(1, msg, ft_strlen(msg));
	exit(1);
}
