/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <yelatman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 10:14:07 by yelatman          #+#    #+#             */
/*   Updated: 2021/12/29 22:13:32 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include <mlx.h>
# include <string.h>
# include <errno.h>
# define BUFFER_SIZE 1
# define VERTICAL 1
# define HORIZONTAL 0
# define ELM_WIDTH 65
# define BUFFER_SIZE 1
# define XK_ESCAPE  53
# define XK_LEFT    2
# define XK_UP     13
# define XK_RIGHT  0
# define XK_DOWN   1
# define KEY_PRESS 2
# define DESTROY_NOTIFY 17
# define BUTTON_PRESS 4
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
	int		x;
	int		y;
	int		fill_color;
	int		border_color ;
	double	width;
	double	height;
}	t_rect;

typedef struct s_elm_position
{
	int	row;
	int	column;
}	t_elm_position;

typedef struct s_map
{
	void			*mlx;
	void			*win;
	int				w_width;
	int				w_height;
	int				line_number;
	int				element_number;
	t_elm_position	player_p;
	t_elm_position	exit_p;
	int				coin_count;
	int				game_over;
	int				player_dead;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	**map_tab;
	t_map	map;
}	t_data;

typedef struct s_vars
{
	int	x;
	int	y;
	int	i;
	int	j;
}	t_vars;

typedef struct s_images
{
	t_img	wl;
	t_img	pl;
	t_img	sp;
	t_img	cd;
	t_img	od;
	t_img	cn;
	t_img	en;
}	t_images;

char	*get_next_line(int fd);
char	*try_get_line(char *str);
char	*extract_line(char **buffer, char **backup, char **line_return);
char	*get_rest_backup(char *buffer);
char	*read_buffer(int fd);
char	*ft_strndup(const char *str, int len);
char	**extract_map(char *file_name);
void	process_map(char **map, int *ln, int *en);
char	read_ch(int fd);
char	*put_ch(char *str, char c);
char	*get_next_line(int fd);
void	draw_map(t_data *data);
void	put_filled_rect(t_img img, t_rect rectangle);
t_img	*initialize_img(char c, void *mlx);
void	get_element_position(char **map, int *i, int *j, char c);
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
int		coin_count(char **map);
void	end_game(t_data *data);
void	init_data(t_data *data, char **map_tab, t_map map);
void	init_map(t_map *map, char **map_tab);
int		handle_move_up(t_data *data);
int		handle_move_down(t_data *data);
int		handle_move_left(t_data *data);
int		handle_move_right(t_data *data);
void	init_images(t_img *elm, t_img *e_space, t_img *coin, t_data *data);
void	init_images_(t_img *wall, t_img *c_door, t_img *o_door, t_data *data);
void	display_image(t_data *data, t_vars variables);
void	init_enemy(t_img *enemy, t_data *data);
void	player_dead(t_data *data, int indx_x, int indx_y);
int		check_for_valid_map(char **map);
int		check_for_invalid_chr(char **map);
int		check_for_walls(char **map);
int		check_for_equal_walls(char **map);
int		l_strlen(char *str);
int		handle_element_right(t_data *data, int indx_x, int indx_y);
int		handle_element_left(t_data *data, int indx_x, int indx_y);
int		handle_element_up(t_data *data, int indx_x, int indx_y);
int		handle_element_down(t_data *data, int indx_x, int indx_y);
int		duplicate(char **map, char c);
int		check_for_duplicate(char **map);
int		check_for_valid_file(char *str);
int		validate_map(char **map, char *str);
void	handle_game_over(t_data *data);
#endif
