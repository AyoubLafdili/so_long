/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:01:00 by alafdili          #+#    #+#             */
/*   Updated: 2024/03/26 00:13:35 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <MLX42.h>

#define opened_door "textures/opened_door.png"
#define closed_door "textures/closed_door.png"
// #define stage_one "textures/stage_one.png"
// #define stage_two "textures/stage_two.png"
#define player_png "textures/player.png"
// #define player_front "textures/player_front.png"
// #define player_left "textures/player_left.png"
// #define player_rigth "textures/player_rigth.png"
#define collectible "textures/collectible.png"
#define corner_wall "textures/corner_wall.png"
#define nested1 "textures/nested_wall1.png"
#define nested2 "textures/nested3.png"
#define floor_png "textures/floor.png"

# define area 50

typedef struct s_flags
{
	int		p_flag;
	int		e_flag;
	int		c_flag;
	int		w_flag;
}	t_flags;

typedef struct 	s_player
{
	int		px;
	int		py;
	int		moves;
}	t_player;

typedef struct s_map
{
	int		map_y;
	int		map_x;
	char	*read_line;
	char	**map;
	char	**map_copy;
}	t_map;


typedef struct s_texture
{
	mlx_texture_t *c_wall;
	mlx_texture_t *nwall1;
	mlx_texture_t *nwall2;
	mlx_texture_t *player;
	mlx_texture_t *floor;
	mlx_texture_t *odoor;
	mlx_texture_t *cdoor;
	mlx_texture_t *collect;
}	t_texture;

typedef struct s_images
{
	mlx_image_t *c_wall;
	mlx_image_t *wall1;
	mlx_image_t *wall2;
	mlx_image_t *gamer;
	mlx_image_t *floor;
	mlx_image_t *odoor;
	mlx_image_t *cdoor;
	mlx_image_t *clt;
}	t_img;


typedef struct s_elements
{
	mlx_t			*mlx;
	mlx_texture_t	*texture[8];
	mlx_image_t		*images[8];
	t_flags			flags;
	t_player		crd;
	t_map			map;
	t_texture		txr;
	t_img			img;
}	t_element;

void	failure_hundler(t_element to_free, int flag);
void	error_hundler(char *str, char **in_Line_map, char *msg, char flag);
char	*map_parsing(char *map_name, t_element *elem);
void	enclosed_walls(char *in_line_map, t_map *list);
void	init_obj(t_element *list);
void	check_valid_path(t_element *list);
int		main(int argc, char *argv[]);
void	_free(char **to_free, char type);
size_t	strlen_char(char *s);

#endif