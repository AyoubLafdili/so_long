/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:03:09 by alafdili          #+#    #+#             */
/*   Updated: 2023/12/01 11:36:26 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	strlen_char(const char *s)
{
	size_t	counter;

	counter = 0;
	while (s[counter] && s[counter] != '\r' && s[counter] != '\n')
		counter++;
	return (counter);
}

size_t	ft_strlen(const char *s, int flag)
{
	size_t	counter;

	counter = 0;
	if (flag == 1)
		return (strlen_char(s));
	while (s[counter])
		counter++;
	return (counter);
}
