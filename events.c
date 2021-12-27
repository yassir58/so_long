# include "solong.h"


int handle_element_right(t_data *data, int indx_x, int indx_y)
{
        data->map.coin_count--;
		data->map_tab[indx_x][indx_y] = '0';
		data->map_tab[indx_x][indx_y - 1] = 'P';
		if (data->map.coin_count == 0)
			end_game(data);
	return (0);
}
int handle_element_left(t_data *data, int indx_x, int indx_y)
{
        data->map.coin_count--;
		data->map_tab[indx_x][indx_y] = '0';
		data->map_tab[indx_x][indx_y + 1] = 'P';
		if (data->map.coin_count == 0)
			end_game(data);
	return (0);
}
int handle_element_up(t_data *data, int indx_x, int indx_y)
{
        data->map.coin_count--;
		data->map_tab[indx_x][indx_y] = '0';
		data->map_tab[indx_x - 1][indx_y] = 'P';
		if (data->map.coin_count == 0)
			end_game(data);
	return (0);
}
int handle_element_down(t_data *data, int indx_x, int indx_y)
{
        data->map.coin_count--;
		data->map_tab[indx_x][indx_y] = '0';
		data->map_tab[indx_x + 1][indx_y] = 'P';
		if (data->map.coin_count == 0)
			end_game(data);
	return (0);
}