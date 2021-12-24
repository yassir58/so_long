
# include "solong.h"

int	key_hook(int keycode, t_data *data)
{
	printf("Hello from key_hook!\n");
    return (0);
}
void	my_mlx_pixel_put(t_img img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
	*(unsigned int*)dst = color;
}
int	handle_keypress(int keysym, t_data *data)
{
    printf ("Key hook ! \n");
	if (keysym == XK_Escape)
    {
        printf ("Escape key pressed \n");
        mlx_destroy_window(data->mlx, data->win);
    }
    else if (keysym == XK_Up)
    {
        move_up(data);
        mlx_clear_window(data->mlx,data->win);
        draw_map(data);
        printf ("move up\n");
    }
    else if (keysym == XK_Down )
    {
        move_down(data);
        mlx_clear_window(data->mlx,data->win);
        draw_map(data); 
    }
    else if (keysym == XK_Left)
    {
        move_left(data);
        mlx_clear_window(data->mlx,data->win);
        draw_map(data);  
    }
    else if (keysym == XK_Right)
    {
        move_right(data);
        mlx_clear_window(data->mlx,data->win);
        draw_map(data); 
    }

	printf("Keypress: %d\n", keysym);
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
    printf("test\n");
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
    printf ("row : %d || column : %d\n",row, column);
    printf ("||%c||\n", map_tab[4][1]);
    map.w_width = ww;
    map.w_height = wh;
    map.line_number = ln;
    map.element_number = en;
    printf ("elem number : %d || line number %d \n", ln, en);
    map.player_p = pl_ps;
    int n = coin_count(map_tab);
    map.coin_count = n;
    printf ("coin count : |%d|\n", n);
    data.map = map;
    data.map_tab = map_tab;
   

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, ww, wh, "Hello world!");
    draw_map(&data);
    mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx);
    printf ("window closed !!\n");
    free(map_tab);
    //mlx_destroy_display(data.vars.mlx);
	free(data.mlx);
}