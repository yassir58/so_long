
#ifndef SOLONG_H
# define SOLONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
#include "libft/libft.h"
# define BUFFER_SIZE 1
# define VERTICAL 1
# define HORIZONTAL 0
# define WINDOW_HEIGHT 1080
# define WINDOW_WIDTH 1920

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}           t_vars;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; 
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_data;

typedef struct s_rect {

int x;
int y;
int fill_color;
double width;
double height;
}       t_rect;

typedef struct s_circle {

int x;
int y;
int radius;
int fill_color;
}       t_circle;

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
void draw_map(char **map, t_data data,int n);
void put_circle(t_data data, t_circle circle);
void put_filled_rect(t_data data ,t_rect rectangle);
#endif