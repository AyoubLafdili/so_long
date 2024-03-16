/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:01:00 by alafdili          #+#    #+#             */
/*   Updated: 2024/03/16 00:50:55 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_flags
{
	char	**map;
	char	**map_copy;
	char	*read_line;
	int		p_flag;
	int		e_flag;
	int		c_flag;
	int		w_flag;
	int		px;
	int		py;
	int		ex;
	int		ey;
	int		map_size;
	int		line_size;
}	t_flags;

void	error_hundler(char *str, char **in_Line_map, char *msg, char flag);
char	*map_parsing(char *map_name, int *count_lines, t_flags *c_list);
void	enclosed_walls(char *in_line_map, int size, t_flags *list);
void	check_valid_path(t_flags vars);
int		main(int argc, char *argv[]);
void	_free(char **to_free, char type);
size_t	strlen_char(char *s);

#endif