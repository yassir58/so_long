NAME=so_long
PATH=./minilibx-opengl
SRC=prog1.c additional.c  utils.c movement.c movement2.c init.c handle_images.c\
additional2.c events.c check_map_utils.c handle_game_over.c
SRC_BONUS=prog1.c additional.c utils.c movement_bonus.c movement2_bonus.c init_bonus.c handle_images_bonus.c check_map_utils.c\
events.c  additional2_bonus.c handle_game_over.c
LIB=mlx
all: $(NAME)
CC=gcc

$(NAME):
	$(CC)  $(SRC) $(CFLAGS)   -l$(LIB) -L./libft -lft  -framework OpenGL -framework AppKit -o $(NAME) 
bonus:
	$(CC) $(SRC_BONUS) $(CFLAGS) -l$(LIB) -L./libft -lft -framework OpenGl -framework AppKit -o so_long_bonus
clean:
	rm -rf so_long
run_test: $(NAME)
	echo "programme starting ... " && ./so_long "./test_maps/test4.ber"
re: clean all
