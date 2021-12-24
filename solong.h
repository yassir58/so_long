
#ifndef SOLONG_H
# define SOLONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include <mlx.h>
# define BUFFER_SIZE 1
# define VERTICAL 1
# define HORIZONTAL 0
# define ELM_WIDTH 65
# define BUFFER_SIZE 1
# define XK_Escape  53
# define XK_Left    124  /* Move left, left arrow */
# define XK_Up      126/* Move up, up arrow */
# define XK_Right  	123  /* Move right, right arrow */
# define XK_Down   125  /* Move down, down arrow */
# define KeyPressMask (1L<<0)
# define ButtonPressMask (1L<<2)
# define KeyPress 02
# define ButtonPress 04
# define TRUE 1
# define FALSE 0


typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; 
	int		line_len;
	int		endian;
}	t_img;


typedef struct s_rect {

int x;
int y;
int fill_color;
int border_color ;
double width;
double height;

}       t_rect;

typedef struct s_player_position {
int row;
int column;
} t_player_position;

typedef struct s_door_position {
int row;
int column;
} t_door_position;

typedef struct s_circle {

int x;
int y;
int radius;
int fill_color;
}       t_circle;

typedef struct s_map 
{
	void *mlx;
	void *win;
	int w_width;
	int w_height;
	int line_number;
	int element_number;
	t_player_position player_p;
	t_door_position door_p;
	int coin_count;
	int end_game;
} t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char **map_tab;
	t_map map;
}	t_data;
char	*get_next_line(int fd);
char	*try_get_line(char *str);
char	*extract_line(char **buffer, char **backup, char **line_return);
char	*get_rest_backup(char *buffer);
char	*read_buffer(int fd);
char	*ft_strndup(const char *str, int len);
char **extract_map(void);
void process_map(char **map, int *ln, int *en);
char read_ch(int fd);
char *put_ch(char *str, char c);
char *get_next_line(int fd);
void draw_map(t_data *data);
void put_circle(t_data data, t_circle circle);
void put_filled_rect(t_img img,t_rect rectangle);
t_img *initialize_img(char c, void *mlx);
void get_element_position(char **map, int *i, int *j, char c);
int move_up(t_data *data);
int move_down(t_data *data);
int move_left(t_data *data);
int move_right(t_data *data);
int coin_count(char **map);
void end_game(t_data *data);
#endif