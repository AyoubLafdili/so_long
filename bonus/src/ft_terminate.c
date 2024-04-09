/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 02:56:23 by alafdili          #+#    #+#             */
/*   Updated: 2024/04/09 00:34:38 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_terminate(t_element param, char *end_msg)
{
	mlx_failure(param, NULL, 3);
	list_clear(param.head);
	_free(param.map.map, 'm');
	mlx_terminate(param.mlx);
	ft_printf("%s\n", end_msg);
	exit(0);
}
