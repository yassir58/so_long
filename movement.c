#include "solong"



void move_up(t_map map, char **map_tab, t_vars vars, t_player_position pl_ps)
{
    int indx_x = pl_ps.row;
    int indx_y = pl_ps.column;
    if (map_tab[indx_x + 1][indx_y] == '0')
    {
        map_tab[indx_x][indx_y] = '0';
        map_tab[indx + 1][indx_x] = 'P';
    }
draw_map(map);
}
void move_down(t_map map,char **map_tab, t_vars vars, t_player_position pl_ps)
{
    int indx_x = pl_ps.row;
    int indx_y = pl_ps.column;
    if (map_tab[indx_x - 1][indx_y] == '0')
    {
        map_tab[indx_x][indx_y] = '0';
        map_tab[indx - 1][indx_x] = 'P';
    }
draw_map(map, map_tab, vars);
}