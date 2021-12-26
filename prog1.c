
# include "solong.h"

void	my_mlx_pixel_put(t_img img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
	*(unsigned int*)dst = color;
}

int	handle_keypress(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
    {
            mlx_destroy_window(data->mlx, data->win);
            exit(0);
    }
    if (data->map.game_over != TRUE)
    {
        if (keysym == XK_Up)
            handle_move_up(data);
        else if (keysym == XK_Down)
           handle_move_down(data);
        else if (keysym == XK_Left)
            handle_move_left(data);
        else if (keysym == XK_Right)
           handle_move_right(data);
    }
	return (0);
}

void put_filled_rect(t_img img, t_rect rectangle)
{
    int i = 0;
    int xv = rectangle.x;
    int yv = rectangle.y;
    
    while (rectangle.width--)
    {
        while (i < rectangle.height)
        {
            my_mlx_pixel_put(img, xv, yv, rectangle.fill_color);
            xv++;
            i++;
        }
        i = 0;
        xv = rectangle.x;
        yv++;
    }
}

int main()
{
    t_map map;
    t_data data;
    char **map_tab ;

    map_tab =  extract_map();
    init_map(&map, map_tab);
    init_data(&data, map_tab, map);
    draw_map(&data);
    mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx);
    free(map_tab);
	free(data.mlx);
}