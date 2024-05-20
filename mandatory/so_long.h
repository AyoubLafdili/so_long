/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:01:00 by alafdili          #+#    #+#             */
/*   Updated: 2024/04/22 14:48:16 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <fcntl.h>
# include "MLX42.h"

# define OPENED_DOOR "textures/opened_door.png"
# define CLOSED_DOOR "textures/closed_door.png"
# define STAGE_ONE "textures/stage_one.png"
# define STAGE_TWO "textures/stage_two.png"    
# define PLAYER "textures/player.png"
# define PLAYER_UP "textures/forward.png"
# define PLAYER_LEFT "textures/left.png"
# define PLAYER_RIGHT "textures/right.png"  
# define COLLECTEBLE "textures/collectible.png"   
# define CORNER_WALL "textures/c_wall.png"   
# define NESTED "textures/nested.png"
# define FLOOR "textures/floor.png" 

# define P 0
# define PU 1
# define PR 2
# define PL 3
# define CD 4
# define S1 5
# define S2 6
# define OD 7
# define CW 8
# define NW 9
# define FL 10
# define C 11

# define SIZE 50

typedef struct s_flags
{
	int		p_flag;
	int		e_flag;
	int		c_flag;
	int		w_flag;
}	t_flags;

typedef struct s_player
{
	int		px;
	int		py;
	int		ex;
	int		ey;
	int		moves;
}	t_player;

typedef struct s_map
{
	int		map_y;
	int		map_x;
	char	*read_line;
	char	**map;
	char	**map_cp;
}	t_map;

typedef struct s_elements
{
	mlx_t			*mlx;
	mlx_texture_t	*txr[12];
	mlx_image_t		*img[12];
	t_flags			flags;
	t_player		crd;
	t_map			map;
}	t_element;

typedef struct s_norm
{
	char	*str;
	char	**other;
	char	*msg;
	char	flag;
}	t_norm;

char	*map_parsing(char *map_name, t_element *elem);
int		check_collectible(char **map);
int		main(int argc, char *argv[]);
int		strlen_char(char *s);
void	mlx_failure(t_element to_free, int flag);
void	err_alert(char *str, char **in_Line_map, char *msg, char flag);
void	enclosed_walls(char *in_line_map, t_map *list);
void	move_player(mlx_key_data_t keydata, void *param);
void	window_hundeler(t_element *list);
void	put_image(t_element obj, mlx_t *mlx, int f);
void	init_obj(t_element *list);
void	check_valid_path(t_element *list);
void	_free(char **to_free, char type);

#endif