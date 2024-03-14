#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

typedef struct s_flags
{
    char **map;
    char *read_line;
    int p_flag;
    int e_flag;
    int c_flag;
    int f_flag;
    int w_flag;
    int px;
    int py;
    int ex;
    int ey;
    int map_size;
    int line_size;

}t_flags;

void error_hundler(char *str, char *in_Line_map, char *msg);
char *map_parsing(char *map_name, int *count_lines, t_flags *c_list);
void enclosed_walls(char *in_line_map, int size, t_flags *list);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
void check_valid_path(t_flags vars);
char	**ft_split(const char *s, char c);
char	*ft_strchr(const char *s, int c);
char	*str_join(const char *s1, const char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int main(int argc, char *argv[]);
void _free(char **to_free, char type);
void	*ft_memset(void *b, int c, size_t len);
int	ft_strncmp(char *s1, char *s2, size_t n);
size_t	ft_strlen(const char *s, int flag);


#endif