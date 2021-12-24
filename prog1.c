
# include "solong.h"

void	my_mlx_pixel_put(t_img img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
	*(unsigned int*)dst = color;
}

int	handle_keypress(int keysym, t_data *data)
{
    int test = data->map.end_game;
    if (test != TRUE)
    {
        if (keysym == XK_Escape)
            mlx_destroy_window(data->mlx, data->win);
        else if (keysym == XK_Up)
        {
            test = move_up(data);
            mlx_clear_window(data->mlx,data->win);
            draw_map(data);
            printf ("move up\n");
        }
        else if (keysym == XK_Down )
        {
            test = move_down(data);
            mlx_clear_window(data->mlx,data->win);
            draw_map(data); 
        }
        else if (keysym == XK_Left)
        {
        test =  move_left(data);
            mlx_clear_window(data->mlx,data->win);
            draw_map(data);  
        }
        else if (keysym == XK_Right)
        {
            test = move_right(data);
            mlx_clear_window(data->mlx,data->win);
            draw_map(data); 
        }
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

    int i = 0;
    int wh = 0, ww = 0;
    int ln= 0;
    int en = 0;
    char **map_tab = extract_map();
    process_map(map_tab, &ln , &en);
    ww = ELM_WIDTH * en ;
    wh = ELM_WIDTH * ln;
    printf ("|ww %d| |wh %d|\n", ww, wh);
    
    int row;
    int column;
    get_element_position(map_tab, &row, &column,'P');
    t_player_position pl_ps;
    pl_ps.row = row;
    pl_ps.column= column;
    map.w_width = ww;
    map.w_height = wh;
    map.line_number = ln;
    map.element_number = en;
    map.player_p = pl_ps;
    int n = coin_count(map_tab);
    map.coin_count = n;
    printf ("coin count : |%d|\n", n);
    data.map = map;
    data.map_tab = map_tab;
    data.map.end_game = FALSE ;
   

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, ww, wh, "Hello world!");
    draw_map(&data);
    mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx);
    printf ("window closed !!\n");
    free(map_tab);
	free(data.mlx);
}