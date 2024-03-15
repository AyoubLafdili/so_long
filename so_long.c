#include "so_long.h"

void check_map_name(char *map_name)
{
	int	name_len;

	name_len = ft_strlen(map_name, 0);
	if (name_len > 4)
	{
		if (!ft_strncmp(&map_name[name_len - 4], ".ber", 4))
			return ;
		else
			error_hundler(NULL, NULL, "Invalid Extension!\n");
	}
	else
		error_hundler(NULL, NULL, "File Name Not Recognized!\n");
}

int main(int argc, char *argv[])
{
	t_flags list;
	char *joined_lines;

	ft_memset(&list, 0, sizeof(t_flags));
	if (argc > 2 || argc == 1)
		error_hundler(NULL, NULL, "Review Your Input Arguments!\n");
	check_map_name(argv[1]);
	joined_lines = map_parsing(argv[1], &list.map_size, &list);
	enclosed_walls(joined_lines, list.map_size, &list);
	check_valid_path(list);
	for(int i = 0; i < list.map_size; i++)
		printf("%s\n", list.map[i]);
	// _free(list.map, 'm');
}