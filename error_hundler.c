#include "so_long.h"

void error_hundler(char *str, char *in_Line_map, char *msg)
{
    if (str)
	    _free(&str, 'p');
    if (in_Line_map)
	    _free(&in_Line_map, 'p');
	write(1, "Error\n", 6);
	write(1, msg, ft_strlen(msg, 0));
	exit(1);
}