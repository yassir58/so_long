/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <yelatman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 12:49:10 by yelatman          #+#    #+#             */
/*   Updated: 2021/12/26 19:33:53 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"



void init_data(t_data *data, char **map_tab, t_map map)
{
    int window_width ;
    int window_height;

    window_width = ELM_WIDTH * map.element_number ;
    window_height = ELM_WIDTH * map.line_number;
    data->map = map;
    data->map_tab = map_tab;
    data->map.game_over = FALSE ;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, window_width, window_height, "Hello world!");
}


void init_map(t_map *map, char **map_tab)
{
    t_elm_position pl_ps;

    process_map(map_tab, &map->line_number , &map->element_number);
    map->w_width = ELM_WIDTH * map->element_number;
    map->w_height = ELM_WIDTH * map->line_number;
    get_element_position(map_tab, &pl_ps.row , &pl_ps.column,'P');
    map->player_p = pl_ps;
    map->coin_count = coin_count(map_tab);
}

void init_images(t_img *monster, t_img *empty_space,t_img *coin, t_data *data)
{
    int elm_w = ELM_WIDTH; 
    int elm_h = ELM_WIDTH;
    t_rect space;
    space.width  = ELM_WIDTH;
    space.height = ELM_WIDTH;
    space.fill_color = 0x00FF0000;
    space.x = 0;
    space.y = 0;
    monster->mlx_img = mlx_xpm_file_to_image(data->mlx, "assets/monster.xpm", &elm_w, &elm_h);
    monster->addr = mlx_get_data_addr(monster->mlx_img, &monster->bpp, &monster->line_len, &monster->endian);
    coin->mlx_img = mlx_xpm_file_to_image(data->mlx, "assets/coin.xpm", &elm_w, &elm_h);
    coin->addr = mlx_get_data_addr(coin->mlx_img, &coin->bpp, &coin->line_len, &coin->endian);
    empty_space->mlx_img = mlx_new_image(data->mlx,  ELM_WIDTH, ELM_WIDTH);
    empty_space->addr = mlx_get_data_addr(empty_space->mlx_img, &empty_space->bpp, &empty_space->line_len, &empty_space->endian);
    put_filled_rect(*empty_space, space);
}

void init_images_(t_img *wall, t_img *closed_door, t_img *open_door, t_data *data)
{
    int elm_w = ELM_WIDTH; 
    int elm_h = ELM_WIDTH;
    wall->mlx_img = mlx_xpm_file_to_image(data->mlx, "assets/wall.xpm", &elm_w, &elm_h);
    wall->addr = mlx_get_data_addr(wall->mlx_img, &wall->bpp, &wall->line_len, &wall->endian);
    closed_door->mlx_img = mlx_xpm_file_to_image(data->mlx, "assets/closed_door.xpm", &elm_w, &elm_h);
    closed_door->addr = mlx_get_data_addr(closed_door->mlx_img, &closed_door->bpp, &closed_door->line_len, &closed_door->endian);
    open_door->mlx_img = mlx_xpm_file_to_image(data->mlx, "assets/open_door.xpm", &elm_w, &elm_h);
    open_door->addr = mlx_get_data_addr(open_door->mlx_img, &open_door->bpp, &open_door->line_len, &open_door->endian);
}

void init_enemy(t_img *enemy, t_data *data)
{
    int elm_w = ELM_WIDTH; 
    int elm_h = ELM_WIDTH;
    enemy->mlx_img = mlx_xpm_file_to_image(data->mlx, "assets/enemy.xpm", &elm_w, &elm_w);
    enemy->addr = mlx_get_data_addr(enemy->mlx_img, &enemy->bpp, &enemy->line_len, &enemy->endian);
}