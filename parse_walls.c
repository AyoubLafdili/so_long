#include "so_long.h"

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
		{
			_free(map, 'm');
			error_hundler(NULL, NULL, "Map Not Enclose By Walls\n");
		}
		else if (tmp == 0 && map[index][tmp] == '1' && index + 1 == size - 1)
		{
			tmp = len;
			index = 1;
		}
		else
			index++;
	}
}

void enclosed_walls(char *in_line_map, int size, t_flags *list)
{
	int i;
	int tmp;

	tmp = 0;
	i = 0;
	list->map = ft_split(in_line_map, '\n');
	if (!list->map)
		error_hundler(in_line_map, NULL, "Cannot Split Map");
	_free(&in_line_map, 'p');
	while (list->map[tmp][i] && list->map[tmp][i] != '\r')
	{
		if(list->map[tmp][i] != '1')
		{
			_free(list->map, 'm');
			error_hundler(NULL, NULL, "Map Not Enclose By Walls\n");
		}
		else if (tmp == 0 && list->map[tmp][i] == '1' 
			&& (list->map[tmp][i + 1] == '\r' || !list->map[tmp][i + 1]))
		{
			tmp = size - 1;
			i = 0;
		}
		else
			i++;
	}
	check_width(list->map, size);
}