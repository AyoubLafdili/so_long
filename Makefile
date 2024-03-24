NAME = so_long

FLAGS = -Wall -Wextra -Werror
COMPILE = cc

MY_LIB = $(LIB_DIR)/libft.a
LIB_DIR = lib/my_lib
MLX_DIR = lib/MLX42
MLX_LIB = $(MLX_DIR)/libmlx42.a -L"/Users/alafdili/.brew/opt/glfw/lib/" -lglfw \
		-framework Cocoa -framework OpenGL -framework IOKit

HEADERS = -I. -Ilib/my_lib -Ilib/MLX42/include/MLX42

SRC = src/free_mem.c src/error_hundler.c src/so_long.c src/parse_char.c src/parse_walls.c \
	src/check_map_path.c src/strlen_char.c src/failure_hundler.c src/mlx_init.c

SRC_OBJECT = $(SRC:.c=.o)

%.o:%.c so_long.h
	$(COMPILE) $(FLAGS) $(HEADERS) -o $@ -c $<

all:$(NAME)

$(NAME):$(SRC_OBJECT) $(SRC_LIB)
	make -C $(LIB_DIR)
	$(COMPILE) $(FLAGS) -o $(NAME) $(SRC_OBJECT) $(MY_LIB) $(MLX_LIB)

clean:
	make -C $(LIB_DIR) clean
	rm -rf $(SRC_OBJECT)

fclean: clean
	make -C $(LIB_DIR) fclean
	rm -rf $(NAME)

re: fclean all