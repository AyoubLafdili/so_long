/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:03:19 by alafdili          #+#    #+#             */
/*   Updated: 2024/03/16 00:50:46 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_elem(char elem, t_flags *calc_elem)
{
	if (elem == 'E')
		(*calc_elem).e_flag++;
	else if (elem == 'P')
		(*calc_elem).p_flag++;
	else if (elem == 'C')
		(*calc_elem).c_flag++;
	else if (elem == '1')
		(*calc_elem).w_flag++;
}

char	*check_valid_char(char *line, t_flags *c_list, char *to_join)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != 'P' && line[i] != 'E' && line[i] != 'C'
			&& line[i] != '0' && line[i] != '1' && line[i] != '\n')
			error_hundler(line, &to_join, "Unexpected Characters!\n", 'p');
		else
		{
			check_map_elem(line[i], c_list);
			i++;
		}
	}
	if (i != (*c_list).line_size)
		error_hundler(line, &to_join, "Shape Correction required!\n", 'p');
	to_join = ft_strjoin(to_join, line);
	if (!to_join)
		error_hundler(line, NULL, "Joining Failed!\n", '0');
	free(line);
	return (to_join);
}

char	*map_parsing(char *map_name, int *count_lines, t_flags *c_list)
{
	int		fd;
	char	*j_lines;

	j_lines = NULL;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		error_hundler(NULL, NULL, "Open Error: No such file\n", '0');
	c_list->read_line = get_next_line(fd);
	if (!c_list->read_line)
		error_hundler(NULL, NULL, "Unable to Read Map!\n", '0');
	c_list->line_size = strlen_char(c_list->read_line);
	while (c_list->read_line)
	{
		j_lines = check_valid_char(c_list->read_line, c_list, j_lines);
		c_list->read_line = NULL;
		c_list->read_line = get_next_line(fd);
		(*count_lines)++;
	}
	if (c_list->e_flag != 1 || c_list->p_flag != 1 || c_list->c_flag == 0
		|| c_list->w_flag < 1)
		error_hundler(j_lines, NULL, "Essential Chars Missing!\n", '0');
	return (j_lines);
}
