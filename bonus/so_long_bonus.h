/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:39:43 by alafdili          #+#    #+#             */
/*   Updated: 2024/04/03 23:09:10 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

#include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>  
# include <fcntl.h>
# include <MLX42.h>

#define opened_door "textures/opened_door.png"
#define closed_door "textures/closed_door.png"
#define stage_one "textures/stage_one.png"
#define stage_two "textures/stage_two.png"    
#define player_png "textures/player.png"
#define player_front "textures/forward.png"
#define player_left "textures/left.png"
#define player_rigth "textures/right.png"    
#define collectible "textures/collectible.png"
#define corner_wall "textures/c_wall_copy.png"
#define nested1 "textures/tree.png"
#define nested2 "textures/_floor.png"
#define floor_png "textures/new_floor.png"
#define enemy "textures/enemy1.png"
   
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


typedef struct s_texture
{
	mlx_texture_t *c_wall;
	mlx_texture_t *nwall1;
	mlx_texture_t *nwall2;
	mlx_texture_t *player;
	mlx_texture_t *p_up;
	mlx_texture_t *_rigth;
	mlx_texture_t *p_left;
	mlx_texture_t *floor;
	mlx_texture_t *odoor;
	mlx_texture_t *cdoor;
	mlx_texture_t *door1;
	mlx_texture_t *door2;
	mlx_texture_t *collect;
	mlx_texture_t *_enemy;
}	t_texture;

typedef struct s_images
{
	mlx_image_t *c_wall;
	mlx_image_t *wall1;
	mlx_image_t *wall2;
	mlx_image_t *gamer;
	mlx_image_t *p_up;
	mlx_image_t *_rigth;
	mlx_image_t *p_left;
	mlx_image_t *floor;
	mlx_image_t *odoor;
	mlx_image_t *cdoor;
	mlx_image_t *door1;
	mlx_image_t *door2;
	mlx_image_t *clt;
	mlx_image_t *_enemy;
}	t_img;

typedef struct s_enemy_cordinate
{
	int x;
	int y;
	struct s_enemy_cordinate *next;
}	t_enemy;

typedef struct s_elements
{
	mlx_t			*mlx;
	mlx_texture_t	*texture[14];
	mlx_image_t		*images[14];
	t_flags			flags;
	t_player		crd;
	t_map			map;
	t_texture		txr;
	t_img			img;
	t_enemy			*head;
	int				pdr;
	int				counter;
}	t_element;

void	mlx_failure(t_element to_free, int flag);
void	err_alert(char *str, char **in_Line_map, char *msg, char flag);
char	*map_parsing(char *map_name, t_element *elem);
void	enclosed_walls(char *in_line_map, t_map *list);
void	add_to_list(t_enemy **head, int ix, int iy);
void	move_player(mlx_key_data_t keydata, void *param);
void	window_hundeler(t_element *list);
void	put_image(t_element *obj, mlx_t *mlx, int f);
void	list_init(t_element *init);
void	init_obj(t_element *list);
void	check_valid_path(t_element *list);
int		check_collectible(char **map);
int		main(int argc, char *argv[]);
void	list_clear(t_enemy *list);
void	_free(char **to_free, char type);
size_t	strlen_char(char *s);

#endif