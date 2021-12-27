NAME=run
PATH=./minilibx-opengl
SRC=prog1.c additional.c  utils.c movement.c movement2.c init.c handle_images.c\
additional2.c events.c check_map_utils.c
LIB=mlx
all: $(NAME)
CC=gcc

$(NAME):
	$(CC)  $(SRC) $(CFLAGS)   -l$(LIB) -L./libft -lft  -framework OpenGL -framework AppKit -o $(NAME) 
clean:
	rm -rf run
run_test: $(NAME)
	echo "programme starting ... " && ./run "test.ber"
re: clean all run_test
