/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_string_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 01:51:43 by alafdili          #+#    #+#             */
/*   Updated: 2024/04/08 22:33:47 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	failure_alert(t_element var, char *f1, char *f2)
{
	_free(&f1, 'p');
	_free(&f2, 'p');
	mlx_failure(var, "to_string failed", 1);
}

char	*to_string(int num, char *type, t_element var)
{
	char	*num_str;
	char	*str;

	str = NULL;
	num_str = NULL;
	num_str = ft_itoa(num);
	if (!num_str)
		failure_alert(var, NULL, NULL);
	str = ft_strjoin(NULL, type);
	if (!str)
		failure_alert(var, num_str, NULL);
	str = ft_strjoin(str, num_str);
	if (!str)
		failure_alert(var, str, num_str);
	_free(&num_str, 'p');
	return (str);
}

void	string_to_window(t_element *c_vars)
{
	mlx_t	*mlx;

	mlx = c_vars->mlx;
	if (mlx_image_to_window(mlx, c_vars->img[BN], 0, 0) == -1)
		mlx_failure(*c_vars, "mlx func failed", 1);
	c_vars->m_str = to_string(c_vars->crd.moves, "moves: ", *c_vars);
	c_vars->c_str = to_string(c_vars->flags.c_flag, "items: ", *c_vars);
	mlx_put_string(mlx, c_vars->c_str, 10, 25);
	mlx_put_string(mlx, c_vars->m_str, 10, 2);
	_free(&c_vars->m_str, 'p');
	c_vars->m_str = NULL;
	_free(&c_vars->c_str, 'p');
	c_vars->c_str = NULL;
}
