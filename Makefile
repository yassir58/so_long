NAME=run
PATH=./minilibx-opengl
SRC=prog1.c additional.c  get_next_line.c get_next_line_utils.c
LIB=mlx
all: $(NAME)
CC=gcc

$(NAME):
	$(CC)  $(SRC) $(CFLAGS)  -L$(PATH) -l$(LIB) -L./libft -lft  -framework OpenGL -framework AppKit -o $(NAME) 
clean:
	rm -rf run
re: clean all
