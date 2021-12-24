#include "solong.h"



void move_up(t_data *data)
{
     printf ("trying to move up\n");
    int indx_x = data->map.player_p.row;
    int indx_y = data->map.player_p.column;
   if (data->map_tab[indx_x - 1][indx_y] == '0')
        {
            printf ("in!@");
            data->map_tab[indx_x][indx_y] = '0';
            data->map_tab[indx_x - 1][indx_y] = 'P';
        }
    get_player_position(data->map_tab, &indx_x, &indx_y);
    data->map.player_p.row = indx_x;
    data->map.player_p.column = indx_y;
}

void move_down(t_data *data)
{
    int indx_x = data->map.player_p.row;
    int indx_y = data->map.player_p.column;
    if (data->map_tab[indx_x + 1][indx_y] == '0')
    {
        data->map_tab[indx_x][indx_y] = '0';
        data->map_tab[indx_x + 1][indx_y] = 'P';
    }
    get_player_position(data->map_tab, &indx_x, &indx_y);
    data->map.player_p.row = indx_x;
    data->map.player_p.column = indx_y;

}