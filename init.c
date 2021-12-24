#include "solong.h"



void init_data(t_data *data, char **map_tab, t_map map)
{
    int window_width ;
    int window_height;

    window_width = ELM_WIDTH * map.element_number ;
    window_height = ELM_WIDTH * map.line_number;
    data->map = map;
    data->map_tab = map_tab;
    data->map.end_game = FALSE ;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, window_width, window_height, "Hello world!");
}


void init_map(t_map *map, char **map_tab)
{
    t_player_position pl_ps;

    process_map(map_tab, &map->line_number , &map->element_number);
    map->w_width = ELM_WIDTH * map->element_number;
    map->w_height = ELM_WIDTH * map->line_number;
    get_element_position(map_tab, &pl_ps.row , &pl_ps.column,'P');
    map->player_p = pl_ps;
    map->coin_count = coin_count(map_tab);
}

