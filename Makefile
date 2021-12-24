NAME=run
PATH=./minilibx-opengl
SRC=prog1.c additional.c  get_next_line.c movement.c movement2.c init.c
LIB=mlx
all: $(NAME)
CC=gcc

$(NAME):
	$(CC)  $(SRC) $(CFLAGS)  -L$(PATH) -l$(LIB) -L./libft -lft  -framework OpenGL -framework AppKit -o $(NAME) 
clean:
	rm -rf run
run_test: $(NAME)
	echo "programme starting ... " && ./run
re: clean all run_test
