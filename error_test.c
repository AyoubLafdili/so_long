#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (s[counter])
		counter++;
	return (counter);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	counter;

	counter = 0;
	if (dstsize > 0)
	{
		while (src[counter] && counter < dstsize - 1)
		{
			dst[counter] = src[counter];
			counter++;
		}
		dst[counter] = '\0';
	}
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;
	size_t	dlen;
	size_t	tlen;
	size_t	counter;

	if (!dst && dstsize == 0)
		return (ft_strlen(src));
	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	counter = 0;
	tlen = 0;
	if (dstsize <= dlen)
		tlen += slen + dstsize;
	else
		tlen += slen + dlen;
	while (src[counter] && (dlen + 1) < dstsize)
	{
		dst[dlen] = src[counter];
		dlen++;
		counter++;
	}
	dst[dlen] = '\0';
	return (tlen);
}


char	*str_join(const char *s1, const char *s2)
{
	char	*constr;
	int		flen;
	int		slen;

	if (!s1)
	{
		constr = (char *)malloc((ft_strlen(s2) + 1) * sizeof(char));
		if (!constr)
			return (NULL);
		ft_strlcpy(constr, s2, ft_strlen(s2) + 1);
		return (constr);
	}
	flen = ft_strlen(s1);
	slen = ft_strlen(s2);
	constr = (char *) malloc((flen + slen + 1) * sizeof(char));
	if (constr == NULL)
		return (NULL);
	ft_strlcpy (constr, s1, flen + 1);
	ft_strlcat (constr, s2, (flen + slen + 1));
	free((char *)s1);
	return (constr);
}

int main()
{
    char **matrix;
    matrix = malloc(sizeof (char *) * 5);
    int i = 0;

    while (i < 4)
    {
        matrix[i] = str_join(matrix[i], "hello\n");
        printf("str#%d: matrix[%d] = %s\n", i, i, matrix[i]);
        i++;
    }
    matrix[i] = NULL;
    i = 0;
    while (matrix[i])
    {
        free(matrix[i]);
        i++;
    }
}