#include "solong.h"

void handle_game_over(t_data *data)
{
    mlx_clear_window(data->mlx, data->win);
    mlx_string_put(data->mlx, data->win , (data->map.w_width / 2), (data->map.w_height / 2), 0xFFFF0000, "game over");
    printf ("game over !\n");
}