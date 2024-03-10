/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:58:04 by alafdili          #+#    #+#             */
/*   Updated: 2023/12/26 22:10:33 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*str_join(const char *s1, const char *s2)
{
	char	*constr;
	int		flen;
	int		slen;

	if (!s1)
	{
		constr = (char *)malloc((ft_strlen(s2) + 1) * sizeof(char));
		if (!constr)
			return (NULL);
		ft_strlcpy(constr, s2, ft_strlen(s2) + 1);
		return (constr);
	}
	flen = ft_strlen(s1);
	slen = ft_strlen(s2);
	constr = (char *) malloc((flen + slen + 1) * sizeof(char));
	if (constr == NULL)
		return (NULL);
	ft_strlcpy (constr, s1, flen + 1);
	ft_strlcat (constr, s2, (flen + slen + 1));
	free((char *)s1);
	return (constr);
}
