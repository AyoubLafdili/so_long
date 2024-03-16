NAME = so_long

FLAGS = -Wall -Wextra -Werror
COMPILE = cc

LIB = my_lib/libft.a
DIR = my_lib
SRC_HEADER = so_long.h
LIB_HEADER = my_lib/libft.h

SRC_LIB = $(DIR)/ft_atoi.c $(DIR)/ft_isalpha.c $(DIR)/ft_memchr.c $(DIR)/ft_memset.c $(DIR)/ft_strlcpy.c $(DIR)/ft_strrchr.c \
		$(DIR)/ft_bzero.c $(DIR)/ft_itoa.c $(DIR)/ft_putendl_fd.c $(DIR)/ft_isascii.c $(DIR)/ft_memcmp.c $(DIR)/ft_strchr.c \
		$(DIR)/ft_strlen.c $(DIR)/ft_tolower.c $(DIR)/ft_split.c $(DIR)/ft_strmapi.c $(DIR)/ft_striteri.c $(DIR)/ft_putnbr_fd.c \
		$(DIR)/ft_calloc.c $(DIR)/ft_isdigit.c $(DIR)/ft_memcpy.c $(DIR)/ft_strdup.c $(DIR)/ft_strncmp.c $(DIR)/ft_toupper.c \
		$(DIR)/ft_strtrim.c $(DIR)/ft_putchar_fd.c $(DIR)/get_next_line.c $(DIR)/ft_lstnew.c $(DIR)/ft_lstadd_front.c \
		$(DIR)/ft_lstsize.c $(DIR)/ft_lstlast.c $(DIR)/ft_lstadd_back.c $(DIR)/ft_lstdelone.c $(DIR)/ft_lstclear.c \
		$(DIR)/ft_lstiter.c $(DIR)/ft_lstmap.c $(DIR)/ft_isalnum.c $(DIR)/ft_isprint.c $(DIR)/ft_memmove.c \
		$(DIR)/ft_strlcat.c $(DIR)/ft_strnstr.c $(DIR)/ft_substr.c $(DIR)/ft_strjoin.c $(DIR)/ft_putstr_fd.c

SRC = free_mem.c error_hundler.c so_long.c parse_char.c parse_walls.c check_map_path.c strlen_char.c

SRC_OBJECT = $(SRC:.c=.o)

%.o:%.c $(SRC_HEADER)
	$(COMPILE) $(FLAGS) -Imy_lib -o $@ -c $<

all:$(NAME)

$(NAME):$(SRC_OBJECT) $(SRC_LIB) $(LIB_HEADER)
	make -C my_lib
	$(COMPILE) $(FLAGS) -o $(NAME) $(SRC_OBJECT) $(LIB)

clean:
	make -C my_lib clean
	rm -rf $(SRC_OBJECT)

fclean: clean
	make -C my_lib fclean
	rm -rf $(NAME)

re: fclean all