/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <yelatman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 12:49:10 by yelatman          #+#    #+#             */
/*   Updated: 2021/12/29 21:43:11 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	init_data(t_data *data, char **map_tab, t_map map)
{
	int	win_w ;
	int	win_h;

	win_w = ELM_WIDTH * map.element_number ;
	win_h = ELM_WIDTH * map.line_number;
	data->map = map;
	data->map_tab = map_tab;
	data->map.game_over = FALSE ;
	data->map.player_dead = FALSE ;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, win_w, win_h, "SO LONG");
}

void	init_map(t_map *map, char **map_tab)
{
	t_elm_position	pl_ps;

	process_map(map_tab, &map->line_number, &map->element_number);
	map->w_width = ELM_WIDTH * map->element_number;
	map->w_height = ELM_WIDTH * map->line_number;
	get_element_position(map_tab, &pl_ps.row, &pl_ps.column, 'P');
	map->player_p = pl_ps;
	map->coin_count = coin_count(map_tab);
}

void	init_images(t_img *elm, t_img *e_space, t_img *coin, t_data *data)
{
	int		elm_size;
	t_rect	space;

	elm_size = ELM_WIDTH;
	space.width = ELM_WIDTH;
	space.height = ELM_WIDTH;
	space.fill_color = 0x00FF0000;
	space.x = 0;
	space.y = 0;
	elm->mlx_img = mlx_xpm_file_to_image(data->mlx,
			"assets/pl_run1.xpm", &elm_size, &elm_size);
	elm->addr = mlx_get_data_addr(elm->mlx_img,
			&elm->bpp, &elm->line_len, &elm->endian);
	coin->mlx_img = mlx_xpm_file_to_image(data->mlx,
			"assets/coin.xpm", &elm_size, &elm_size);
	coin->addr = mlx_get_data_addr(coin->mlx_img,
			&coin->bpp, &coin->line_len, &coin->endian);
	e_space->mlx_img = mlx_new_image(data->mlx, ELM_WIDTH, ELM_WIDTH);
	e_space->addr = mlx_get_data_addr(e_space->mlx_img, &e_space->bpp,
			&e_space->line_len, &e_space->endian);
	put_filled_rect(*e_space, space);
}

void	init_images_(t_img *wall, t_img *c_door, t_img *o_door, t_data *data)
{
	int	elm_size;

	elm_size = ELM_WIDTH;
	wall->mlx_img = mlx_xpm_file_to_image(data->mlx,
			"assets/wall.xpm", &elm_size, &elm_size);
	wall->addr = mlx_get_data_addr(wall->mlx_img,
			&wall->bpp, &wall->line_len, &wall->endian);
	c_door->mlx_img = mlx_xpm_file_to_image(data->mlx,
			"assets/closed_door.xpm", &elm_size, &elm_size);
	c_door->addr = mlx_get_data_addr(c_door->mlx_img,
			&c_door->bpp, &c_door->line_len, &c_door->endian);
	o_door->mlx_img = mlx_xpm_file_to_image(data->mlx,
			"assets/open_door.xpm", &elm_size, &elm_size);
	o_door->addr = mlx_get_data_addr(o_door->mlx_img, &o_door->bpp,
			&o_door->line_len, &o_door->endian);
}

void	init_enemy(t_img *enemy, t_data *data)
{
	int	elm_size;

	elm_size = ELM_WIDTH;
	enemy->mlx_img = mlx_xpm_file_to_image(data->mlx,
			"assets/enemy.xpm", &elm_size, &elm_size);
	enemy->addr = mlx_get_data_addr(enemy->mlx_img, &enemy->bpp,
			&enemy->line_len, &enemy->endian);
}
