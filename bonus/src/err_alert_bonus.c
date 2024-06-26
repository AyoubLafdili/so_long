/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_alert_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:34:02 by alafdili          #+#    #+#             */
/*   Updated: 2024/04/21 22:25:45 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	err_alert(char *str, char **other, char *msg, char flag)
{
	if (str)
	{
		get_next_line(-1);
		_free(&str, 'p');
	}
	if (flag == 'm')
	{
		if (other)
			_free(other, 'm');
	}
	if (flag == 'p')
	{
		if (other && *other)
			_free(other, 'p');
	}
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}
