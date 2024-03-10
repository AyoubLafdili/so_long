NAME = so_long
FLAGS = -Wall -Wextra -Werror
COMPILE = cc
SRC_HEADER = so_long.h
SRC = ft_strlen.c ft_strncmp.c main.c str_join.c ft_strlcat.c get_next_line.c \
	ft_strlcpy.c ft_substr.c ft_strchr.c

SRC_OBJECT = $(SRC:.c=.o)

%.o:%.c $(SRC_HEADER)
	$(COMPILE) $(FLAGS) -o $@ -c $<

$(NAME):$(SRC_OBJECT)
	$(COMPILE) $(FLAGS) -g -o $(NAME) $(SRC_OBJECT)

clean:
	rm -rf $(SRC_OBJECT)
fclean: clean
	rm -rf $(NAME)
re: fclean $(NAME)