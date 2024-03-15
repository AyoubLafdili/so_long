#include "so_long.h"

void error_hundler(char *str, char *in_line_map, char *msg)
{
    if (str)
	    _free(&str, 'p');
    if (in_line_map)
	    _free(&in_line_map, 'p');
	write(1, "Error\n", 6);
	write(1, msg, ft_strlen(msg, 0));
	exit(1);
}