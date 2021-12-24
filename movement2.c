#include "solong.h"



int handle_move_up(t_data *data)
{
    data->map.end_game = move_up(data);
    mlx_clear_window(data->mlx,data->win);
    draw_map(data);
}

int handle_move_down(t_data *data)
{
    data->map.end_game = move_down(data);
    mlx_clear_window(data->mlx,data->win);
    draw_map(data); 
}

int handle_move_left(t_data *data)
{
    data->map.end_game =  move_left(data);
    mlx_clear_window(data->mlx,data->win);
    draw_map(data); 
}

int handle_move_right (t_data *data)
{
    data->map.end_game = move_right(data);
    mlx_clear_window(data->mlx,data->win);
    draw_map(data); 
}