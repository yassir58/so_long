
# include "solong.h"

int	key_hook(int keycode, t_vars *vars)
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

/*
void	render_background(t_data data, int color)
{
	int	i;
	int	j;

	if (data.win_ptr == NULL)
		return ;
	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			my_mlx_pixel_put(data, j++, i, color);
		++i;
	}
}*/
/*
void put_line(t_data data , int x, int y, int height, int position, int color)
{
    int i = 0;
    int xv = x;
    int yv = y;
    printf ("position %d  xv %d yv %d\n",position, xv , yv);
    while (i < height)
    {
        my_mlx_pixel_put(data , xv, yv ,color);
        if (position)
            xv++;
        else
            yv++;
        i++;
    }
}*/
/*
void put_rect_border(t_data data , t_rect rectangle_border)
{
    put_line(data, rectangle_border.x, rectangle_border.y, rectangle_border.height, VERTICAL, rectangle_border.border_color);
    put_line(data, rectangle_border.x, rectangle_border.y, rectangle_border.width, HORIZONTAL, rectangle_border.border_color);
    put_line(data, (rectangle_border.x + rectangle_border.height), rectangle_border.y, rectangle_border.width, HORIZONTAL, rectangle_border.border_color);
    put_line(data, rectangle_border.x, (rectangle_border.y + rectangle_border.width), rectangle_border.height, VERTICAL, rectangle_border.border_color);
}*/

void put_filled_rect(t_img img, t_rect rectangle)
{
    int i = 0;
    int xv = rectangle.x;
    int yv = rectangle.y;
    xv++;
    yv++;
    rectangle.width--;
    rectangle.height--;
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
/*
void put_circle(t_data data, t_circle circle)
{
    int i = 0;
    int or_x = circle.x;
    int or_y = circle.y;

    for(int y=-circle.radius; y<=circle.radius; y++)
        for(int x=-circle.radius; x<=circle.radius; x++)
            if(circle.x*circle.x+circle.y*circle.y <= circle.radius*circle.radius)
                my_mlx_pixel_put(data,or_x+x, or_y + circle.y, circle.fill_color);
}*/

int main()
{
    t_vars vars;
    t_map map;
    t_img test;

    int i = 0;
    int wh = 0, ww = 0;
    int ln= 0;
    int en = 0;
    char **map_tab = extract_map();
    process_map(map_tab, &ln , &en);
    ww = ELM_WIDTH * en ;
    wh = ELM_WIDTH * ln;
    printf ("|ww %d| |wh %d|\n", ww, wh);
    

    map.mlx = vars.mlx;
    map.win = vars.win;
    map.w_width = ww;
    map.w_height = wh;
    map.line_number = ln;
    map.element_number = en;

   

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, ww, wh, "Hello world!");
    //draw_map(map, map_tab, vars);
	mlx_loop(vars.mlx);
    free(map_tab);
    free(vars.mlx);
}