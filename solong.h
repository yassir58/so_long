
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
# define XK_Left    124
# define XK_Up      126
# define XK_Right  	123 
# define XK_Down   125
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


typedef struct s_rect 
{
	int x;
	int y;
	int fill_color;
	int border_color ;
	double width;
	double height;
}       t_rect;

typedef struct s_elm_position {
int row;
int column;
} t_elm_position;

typedef struct s_map 
{
	void *mlx;
	void *win;
	int w_width;
	int w_height;
	int line_number;
	int element_number;
	t_elm_position player_p;
	t_elm_position exit_p;
	int coin_count;
	int game_over;
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
void put_filled_rect(t_img img,t_rect rectangle);
t_img *initialize_img(char c, void *mlx);
void get_element_position(char **map, int *i, int *j, char c);
int move_up(t_data *data);
int move_down(t_data *data);
int move_left(t_data *data);
int move_right(t_data *data);
int coin_count(char **map);
void end_game(t_data *data);
void init_data(t_data *data, char **map_tab, t_map map);
void init_map(t_map *map, char **map_tab);
void handle_move_up(t_data *data);
void handle_move_down(t_data *data);
void handle_move_left(t_data *data);
void handle_move_right (t_data *data);
void init_images(t_img *monster, t_img *empty_space,t_img *coin, t_data *data);
void init_images_(t_img *wall, t_img *closed_door, t_img *open_door, t_data *data);
void display_image(t_data *data, int i, int j, int x, int y);
void init_enemy(t_img *enemy, t_data *data);
#endif