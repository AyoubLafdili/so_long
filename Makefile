NAME = so_long
B_NAME = so_long_bonus

M_DIR = mandatory/src
B_DIR = bonus/src
LIB_DIR = lib/libft
MLX_DIR = lib/MLX42/build

MY_LIB = -L$(LIB_DIR) -lft
MLX_LIB = -L$(MLX_DIR) -lmlx42 -L"/Users/alafdili/.brew/opt/glfw/lib/" -lglfw \
		

INCLUDE = -Ilib/libft -Ilib/MLX42/include/MLX42
M_HEADERS = -Imandatory $(INCLUDE)
B_HEADERS = -Ibonus $(INCLUDE)

COMPILE = cc
FLAGS = -Wall -Wextra -Werror


M_SRC = $(M_DIR)/parse_char.c $(M_DIR)/parse_walls.c $(M_DIR)/window_hundler.c \
		$(M_DIR)/check_map_path.c $(M_DIR)/strlen_char.c $(M_DIR)/mlx_failure.c \
		$(M_DIR)/init_objects.c $(M_DIR)/player_moves.c $(M_DIR)/display_images.c \
		$(M_DIR)/check_collectible.c $(M_DIR)/free_mem.c $(M_DIR)/err_alert.c \
		$(M_DIR)/so_long.c 

B_SRC = $(B_DIR)/check_collectible_bonus.c $(B_DIR)/display_images_bonus.c \
		$(B_DIR)/free_mem_bonus.c $(B_DIR)/init_objects_bonus.c \
		$(B_DIR)/parse_char_bonus.c $(B_DIR)/player_moves_bonus.c \
		$(B_DIR)/window_hundler_bonus.c $(B_DIR)/check_map_path_bonus.c \
		$(B_DIR)/err_alert_bonus.c $(B_DIR)/mlx_failure_bonus.c \
		$(B_DIR)/parse_walls_bonus.c $(B_DIR)/so_long_bonus.c \
		$(B_DIR)/strlen_char_bonus.c $(B_DIR)/add_to_list.c \
		$(B_DIR)/list_clear.c $(B_DIR)/list_init.c \
		$(B_DIR)/display_string_bonus.c $(B_DIR)/ft_terminate.c

M_OBJ = $(M_SRC:.c=.o)
B_OBJ = $(B_SRC:.c=.o)

all:$(MLX_DIR) $(NAME)

$(MLX_DIR):
	if [ -e build/libmlx42.a ]; then \
		@echo "\033[1;32mlibmlx42.a exists\033[1;m"; \
	else \
		echo "\033[1;32mbuilding mlx lib ...\033[1;m"; \
		cd lib/MLX42; cmake -B build; make -C build; \
	fi

$(B_DIR)/%.o: $(B_DIR)/%.c bonus/so_long_bonus.h
	$(COMPILE) $(FLAGS) $(B_HEADERS) -o $@ -c $<

$(M_DIR)/%.o:$(M_DIR)/%.c mandatory/so_long.h
	$(COMPILE) $(FLAGS) $(M_HEADERS) -o $@ -c $<


$(B_NAME): $(B_OBJ)
	make -C $(LIB_DIR)
	$(COMPILE) $(FLAGS) -o $(B_NAME) $(B_OBJ) $(MY_LIB) $(MLX_LIB)

$(NAME):$(M_OBJ)
	make -C $(LIB_DIR)
	$(COMPILE) $(FLAGS) -o $(NAME) $(M_OBJ) $(MY_LIB) $(MLX_LIB)

bonus: $(B_NAME)

clean:
	make -C $(LIB_DIR) clean
	rm -rf $(M_OBJ) $(B_OBJ)

fclean: clean
	make -C $(LIB_DIR) fclean
	rm -rf $(NAME) $(B_NAME)

re: fclean all