/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:39:43 by alafdili          #+#    #+#             */
/*   Updated: 2024/04/22 14:49:18 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "libft.h"
# include <fcntl.h>
# include <MLX42.h>

//Door:
# define OPENED_DOOR "textures/opened_door.png"
# define CLOSED_DOOR "textures/closed_door.png"
# define STAGE_ONE "textures/stage_one.png"
# define STAGE_TWO "textures/stage_two.png" 

//Player:
# define PLAYER "textures/player.png"
# define PLAYER_UP "textures/forward.png"
# define PLAYER_LEFT "textures/left.png"
# define PLAYER_RIGHT "textures/right.png" 

//Walls:
# define CORNER_WALL "textures/c_wall.png"   
# define NESTED "textures/nested.png"

//Floor:
# define FLOOR "textures/floor.png"

//Enemy:
# define ENEMY "textures/enemy.png"

//Other:
# define COLLECTEBLE "textures/collectible.png"  
# define BANNER "textures/banner.png"

# define SIZE 50

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
# define I 11
# define C 12
# define BN 13

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

typedef struct s_enemy_cordinate
{
	struct s_enemy_cordinate	*next;
	int							x;
	int							y;
}	t_enemy;

typedef struct s_norm
{
	char	*str;
	char	**other;
	char	*msg;
	char	flag;
}	t_norm;

typedef struct s_elements
{
	mlx_t			*mlx;
	mlx_texture_t	*txr[14];
	mlx_image_t		*img[14];
	t_flags			flags;
	t_player		crd;
	t_map			map;
	t_enemy			*head;
	int				pdr;
	char			*m_str;
	char			*c_str;
}	t_element;

char	*map_parsing(char *map_name, t_element *elem);
int		add_to_list(t_enemy **head, int ix, int iy);
int		strlen_char(char *s);
int		check_collectible(char **map);
int		main(int argc, char *argv[]);
void	mlx_failure(t_element to_free, char *error_msg, int flag);
void	err_alert(char *str, char **in_Line_map, char *msg, char flag);
void	move_player(mlx_key_data_t keydata, void *param);
void	window_hundeler(t_element *list);
void	put_image(t_element obj);
void	ft_terminate(t_element param, char *end_msg);
void	list_init(t_element *init);
void	init_obj(t_element *list);
void	check_valid_path(t_element *list);
void	enclosed_walls(char *in_line_map, t_element *list);
void	string_to_window(t_element *c_vars);
void	list_clear(t_enemy *list);
void	_free(char **to_free, char type);

#endif