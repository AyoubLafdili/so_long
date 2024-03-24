/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:03:19 by alafdili          #+#    #+#             */
/*   Updated: 2024/03/22 18:06:08 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_elem(char elem, t_flags *calc_elem)
{
	if (elem == 'E')
		calc_elem->e_flag++;
	else if (elem == 'P')
		calc_elem->p_flag++;
	else if (elem == 'C')
		calc_elem->c_flag++;
	else if (elem == '1')
		calc_elem->w_flag++;
}

char	*check_valid_char(t_element *c_list, char *to_join)
{
	int	i;
	char *line;

	line = c_list->map.read_line;
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != 'P' && line[i] != 'E' && line[i] != 'C'
			&& line[i] != '0' && line[i] != '1' && line[i] != '\n')
			error_hundler(line, &to_join, "Unexpected Characters!\n", 'p');
		else
		{
			check_map_elem(line[i], &c_list->flags);
			i++;
		}
	}
	if (i != c_list->map.map_x)
		error_hundler(line, &to_join, "Shape Correction required!\n", 'p');
	to_join = ft_strjoin(to_join, line);
	if (!to_join)
		error_hundler(line, NULL, "Joining Failed!\n", '0');
	free(line);
	return (to_join);
}

char	*map_parsing(char *map_name, t_element *elem)
{
	int		fd;
	char	*j_lines;

	j_lines = NULL;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		error_hundler(NULL, NULL, "Open Error: No such file\n", '0');
	elem->map.read_line = get_next_line(fd);
	if (!elem->map.read_line)
		error_hundler(NULL, NULL, "Unable to Read Map!\n", '0');
	elem->map.map_x = strlen_char(elem->map.read_line);
	while (elem->map.read_line)
	{
		j_lines = check_valid_char(elem, j_lines);
		elem->map.read_line = NULL;
		elem->map.read_line = get_next_line(fd);
		elem->map.map_y++;
	}
	if (elem->flags.e_flag != 1 || elem->flags.p_flag != 1 || elem->flags.c_flag == 0
		|| elem->flags.w_flag < 1)
		error_hundler(j_lines, NULL, "Essential Chars Missing!\n", '0');
	return (j_lines);
}
