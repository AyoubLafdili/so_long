#include "so_long.h"

void init_coordinate(char **map, char elem, int *x_elem, int *y_elem)
{
    int x;
    int y;

    y = 0;
    while (map[y] != NULL)
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == elem)
            {
                *x_elem = x;
                *y_elem = y;
                break ;
            }
            x++;
        }
        y++;
    }
    
}

void flood_fill(char **map, int y, int x,  int map_size, char new)
{
    if (y < 0 || y >= map_size || x < 0
        || (size_t)x >= ft_strlen(map[0], 1) || map[y][x] == new
            || (map[y][x] != '0' && map[y][x] != 'C'
                && map[y][x] != 'P'))
                    return ;
    map[y][x] = new;
    flood_fill(map, y - 1, x, map_size, new);
    flood_fill(map, y + 1, x, map_size, new);
    flood_fill(map, y, x - 1, map_size, new);
    flood_fill(map, y, x + 1, map_size, new);

}

void check_valid_path(t_flags vars)
{
    init_coordinate(vars.map, 'P', &vars.px, &vars.py);
    init_coordinate(vars.map, 'E', &vars.ex, &vars.ey);
    flood_fill(vars.map, vars.py, vars.px, vars.map_size, '9');
}