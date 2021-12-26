#include "solong.h"



void handle_move_up(t_data *data)
{
    data->map.game_over = move_up(data);
    mlx_clear_window(data->mlx,data->win);
    draw_map(data);
}

void handle_move_down(t_data *data)
{
    data->map.game_over = move_down(data);
    mlx_clear_window(data->mlx,data->win);
    draw_map(data); 
}

void handle_move_left(t_data *data)
{
    data->map.game_over =  move_left(data);
    mlx_clear_window(data->mlx,data->win);
    draw_map(data); 
}

void handle_move_right (t_data *data)
{
    data->map.game_over = move_right(data);
    mlx_clear_window(data->mlx,data->win);
    draw_map(data); 
}