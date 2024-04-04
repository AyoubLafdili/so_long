/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:36:00 by alafdili          #+#    #+#             */
/*   Updated: 2024/04/04 13:41:16 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	fun(void)
{
	system("leaks so_long");
}

void	check_map_name(char *map_name)
{
	int	name_len;

	name_len = ft_strlen(map_name);
	if (name_len > 4)
	{
		if (!ft_strncmp(&map_name[name_len - 4], ".ber", 4))
			return ;
		else
			err_alert(NULL, NULL, "Invalid Extension!", '0');
	}
	else
		err_alert(NULL, NULL, "File Name Not Recognized!", '0');
}

int	main(int argc, char *argv[])
{
	t_element	list;
	char		*joined_lines;

	atexit(fun);
	ft_memset(&list, 0, sizeof(t_element));
	if (argc != 2)
		err_alert(NULL, NULL, "Review Your Input Arguments!", '0');
	check_map_name(argv[1]);
	joined_lines = map_parsing(argv[1], &list);
	enclosed_walls(joined_lines, &list.map);
	list_init(&list);
	check_valid_path(&list);
	window_hundeler(&list);
	_free(list.map.map, 'm');
	mlx_terminate(list.mlx);
	return (0);
}
