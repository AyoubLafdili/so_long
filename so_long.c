#include "so_long.h"

void error_hundler(char *str, char *msg, int flag)
{
	if (flag == 1)
	{
		perror("Error\nOpen Error");
		exit(1);
	}
	if (str)
		free(str);
	write(1, "Error\n", 6);
	write(1, msg, ft_strlen(msg, 0));
	exit(1);
}

void check_map_name(char *map_name)
{
	int	name_len;

	name_len = ft_strlen(map_name, 0);
	if (name_len > 4)
	{
		if (!ft_strncmp(&map_name[name_len - 4], ".ber", 4))
			return ;
		else
			error_hundler(NULL, "Invalid Extension!\n", 0);
	}
	else
		error_hundler(NULL, "File Name Not Recognized!\n", 0);
}


void check_map_elem(char elem, t_flags *calc_elem)
{
	if (elem == 'E')
		(*calc_elem).e_flag++;
	else if (elem == 'P')
		(*calc_elem).p_flag++;
	else if (elem == 'C')
		(*calc_elem).c_flag++;
	else if (elem == '1')
		(*calc_elem).w_flag++;
	else if (elem == '0')
		(*calc_elem).f_flag++;
}

char *check_valid_char(char *line, t_flags *c_var_list, char *map_in_line)
{
	int i;

	i = 0;
	while (line[i] && line[i] != '\n' && line[i] != '\r')
	{
		if (line[i] != 'P' && line[i] != 'E' && line[i] != 'C' 
		&& line[i] != '0' && line[i] != '1' && line[i] != '\n')
			error_hundler(line, "Unexpected Characters Found!\n", 0);
		else
		{
			check_map_elem(line[i], c_var_list);
			i++;
		}
	}
	if (i != (*c_var_list).line_size)
		error_hundler(line, "Map Shape Correction is required!\n", 0);
	map_in_line = str_join(map_in_line, line);
	if (!map_in_line)
		error_hundler(line, "Joining Failed!\n", 0);
	free(line);
	return (map_in_line);
}

void check_width(char **map, int size)
{
	int len;
	int index;
	int tmp;

	len = ft_strlen(map[0], 1) - 1;
	index = 1;
	tmp = 0;

	while (index < size - 1)
	{
		if (map[index][tmp] != '1')
			error_hundler(NULL, "Map Not Enclose By Walls\n", 0);
		else if (tmp == 0 && map[index][tmp] == '1' && index + 1 == size - 1)
		{
			tmp = len;
			index = 1;
		}
		else
			index++;
	}
}

void enclosed_walls(char *in_line_map, int size)
{
	int i;
	int tmp;
	char **map;

	tmp = 0;
	map = NULL;
	i = 0;
	map = ft_split(in_line_map, '\n');
	while (map[tmp][i] && map[tmp][i] != '\r')
	{
		if(map[tmp][i] != '1')
			error_hundler(in_line_map, "Map Not Enclose By Walls\n", 0);
		else if (tmp == 0 && map[tmp][i] == '1' 
			&& (map[tmp][i + 1] == '\r' || !map[tmp][i + 1]))
		{
			tmp = size - 1;
			i = 0;
		}
		else
			i++;
	}
	check_width(map, size);
}

char *map_parsing(char *map_name, int *count_lines)
{
	int fd;
	t_flags var_list;
	char *map_line;
	char *map_in_line;

	map_line = NULL;
	map_in_line = NULL;
	ft_memset(&var_list, 0, sizeof(t_flags));
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		error_hundler(NULL, NULL, 1);
	map_line = get_next_line(fd);
	if (!map_line)
		error_hundler(NULL, "Unable to Read Map!\n", 0);
	var_list.line_size = ft_strlen(map_line, 1);
	while (map_line)
	{
		map_in_line = check_valid_char(map_line, &var_list, map_in_line);
		map_line = NULL;
		map_line = get_next_line(fd);
		(*count_lines)++;
	}
	if (var_list.e_flag != 1 || var_list.p_flag != 1 || var_list.c_flag == 0
		|| var_list.f_flag < 1 || var_list.w_flag < 1)
		error_hundler(NULL, "Missing Some Essential Characters!\n", 0);
	return (map_in_line);
}

int main(int argc, char *argv[])
{
	char *in_line;
	int map_lines;

	map_lines = 0;
	if (argc > 2 || argc == 1)
		error_hundler(NULL, "Review Your Input Arguments!\n", 0);
	check_map_name(argv[1]);
	in_line = map_parsing(argv[1], &map_lines);
	enclosed_walls(in_line, map_lines);
}
