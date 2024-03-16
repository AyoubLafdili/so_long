/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:01:36 by alafdili          #+#    #+#             */
/*   Updated: 2024/03/16 00:45:13 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_name(char *map_name)
{
	int	name_len;

	name_len = ft_strlen(map_name);
	if (name_len > 4)
	{
		if (!ft_strncmp(&map_name[name_len - 4], ".ber", 4))
			return ;
		else
			error_hundler(NULL, NULL, "Invalid Extension!\n", '0');
	}
	else
		error_hundler(NULL, NULL, "File Name Not Recognized!\n", '0');
}

int	main(int argc, char *argv[])
{
	t_flags	list;
	char	*joined_lines;

	ft_memset(&list, 0, sizeof(t_flags));
	if (argc > 2 || argc == 1)
		error_hundler(NULL, NULL, "Review Your Input Arguments!\n", '0');
	check_map_name(argv[1]);
	joined_lines = map_parsing(argv[1], &list.map_size, &list);
	enclosed_walls(joined_lines, list.map_size, &list);
	check_valid_path(list);
}
