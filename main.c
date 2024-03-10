#include "so_long.h"

void error_hundler(char *str)
{
	if (str)
		free(str);
	write(1, "Error\n", 6);
	exit(0);
}

void check_map_name(char *map_name)
{
	int	name_len;

	name_len = ft_strlen(map_name);
	if (name_len > 4)
	{
		if (!ft_strncmp(&map_name[name_len - 4], ".ber", 4))
			return ;
		else
			error_hundler(NULL);
	}
	else
		error_hundler(NULL);
}

void map_parsing(char *map_name, int *map_size)
{
	int i;
	int fd;
	int P_flag = 0;
	int E_flag = 0;
	int C_flag = 0;
	int f_flag = 0;
	int w_flag = 0;
	int line_size = 0;
	char *map_line;
	map_line = NULL;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		exit(0);
	}
	map_line = get_next_line(fd);
	// printf("line: %s\n", map_line);
	line_size = ft_strlen(map_line);
	printf("line size: %d\n", line_size);
	while (map_line)
	{

		printf("line : %s\n", map_line);
		printf("line len: %ld\n", ft_strlen(map_line));


		(*map_size)++;
		i = 0;
		while (map_line[i])
		{
			if (map_line[i] != 'P' && map_line[i] != 'E' && map_line[i] != 'C' 
			&& map_line[i] != '0' && map_line[i] != '1' && map_line[i] != '\n' && map_line[i] != '\r')
				error_hundler(map_line);
			else
			{
				if (map_line[i] == 'E')
				{
					E_flag++;
					i++;

				}
				else if (map_line[i] == 'P')
				{
					P_flag++;
					i++;
				}
				else if (map_line[i] == 'C')
				{
					C_flag++;
					i++;
				}
				else if (map_line[i] == '1')
				{
					w_flag++;
					i++;
				}
				else if (map_line[i] == '0')
				{
					f_flag++;
					i++;
				}
				else
					i++;
				
			}
		}
		printf("i = %d\n", i);
		if (i != line_size)
			error_hundler(map_line);
		free(map_line);
		map_line = NULL;
		map_line = get_next_line(fd);
	}
	if (E_flag != 1 || P_flag != 1 || C_flag == 0 || f_flag < 1 || w_flag < 1)
		error_hundler(NULL);
}

int main(int argc, char *argv[])
{
	int map_size;

	map_size = 0;
	if (argc > 2 || argc == 1)
		error_hundler(NULL);
	check_map_name(argv[1]);
	map_parsing(argv[1], &map_size);
}
