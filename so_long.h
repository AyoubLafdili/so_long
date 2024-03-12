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
    int **map;
    int p_flag;
    int e_flag;
    int c_flag;
    int f_flag;
    int w_flag;
    int line_size;

}t_flags;

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
char	**ft_split(const char *s, char c);
char	*ft_strchr(const char *s, int c);
char	*str_join(const char *s1, const char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int main(int argc, char *argv[]);
void	*ft_memset(void *b, int c, size_t len);
int	ft_strncmp(char *s1, char *s2, size_t n);
size_t	ft_strlen(const char *s, int flag);


#endif