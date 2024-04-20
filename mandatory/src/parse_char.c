/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:03:19 by alafdili          #+#    #+#             */
/*   Updated: 2024/04/20 15:43:53 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	avoid_norm(int fd, t_norm compound)
{
	t_norm	vars;

	vars = compound;
	close(fd);
	err_alert(vars.str, vars.other, vars.msg, vars.flag);
}

void	calc_map_elem(char elem, t_flags *calc_elem)
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

char	*check_valid_char(t_element *c_list, char *to_join, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = c_list->map.read_line;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != 'P' && line[i] != 'E' && line[i] != 'C'
			&& line[i] != '0' && line[i] != '1')
			avoid_norm(fd, (t_norm){line, &to_join, "Unexpected Chars", 'p'});
		else
		{
			calc_map_elem(line[i], &c_list->flags);
			i++;
		}
	}
	if (i != c_list->map.map_x)
		avoid_norm(fd, (t_norm){line, &to_join, "Adjust Shape!", 'p'});
	to_join = ft_strjoin(to_join, line);
	if (!to_join)
		avoid_norm(fd, (t_norm){line, NULL, "Joining Failed!", 'p'});
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
		err_alert(NULL, NULL, "Open Error: No such file", '0');
	elem->map.read_line = get_next_line(fd);
	if (!elem->map.read_line)
		avoid_norm(fd, (t_norm){NULL, NULL, "Unable to Read Map!", '0'});
	elem->map.map_x = strlen_char(elem->map.read_line);
	while (elem->map.read_line)
	{
		j_lines = check_valid_char(elem, j_lines, fd);
		elem->map.read_line = NULL;
		elem->map.read_line = get_next_line(fd);
		elem->map.map_y++;
	}
	if (elem->flags.e_flag != 1 || elem->flags.p_flag != 1
		|| elem->flags.c_flag == 0)
		avoid_norm(fd, (t_norm){j_lines, NULL, "Chars Missing!", '0'});
	if (j_lines[((elem->map.map_x + 1) * elem->map.map_y) - 1] == '\n')
		avoid_norm(fd, (t_norm){j_lines, NULL, "Unexpected Chars", '0'});
	close(fd);
	return (j_lines);
}
