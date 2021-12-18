# include <mlx.h>
# include <stdio.h>
# include "solong.h"

int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
    return (0);
}
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
	*(unsigned int*)dst = color;
}


void	render_background(t_data *data, int color)
{
	int	i;
	int	j;

	if (data->win_ptr == NULL)
		return ;
	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			my_mlx_pixel_put(data, j++, i, color);
		++i;
	}
}

void put_line(t_data data , int x, int y, int height, int position)
{
    int i = 0;
    int xv = x;
    int yv = y;
    printf ("position %d  xv %d yv %d\n",position, xv , yv);
    while (i < height)
    {
        my_mlx_pixel_put(&data , xv, yv ,0x00FF0000);
        if (position)
            xv++;
        else
            yv++;
        i++;
    }
}

void put_rect_border(t_data data , int x, int y, int height, int width)
{
    put_line(data, x, y, height, VERTICAL);
    put_line(data, x, y, width, HORIZONTAL);
    put_line(data, (x + height), y, width, HORIZONTAL);
    put_line(data, x, (y + width), height, VERTICAL);
}

void put_filled_rect(t_data data, t_rect rectangle)
{
    int i = 0;
    int xv = rectangle.x;
    int yv = rectangle.y;
    while (rectangle.width--)
    {
        while (i < rectangle.height)
        {
            my_mlx_pixel_put(&data, xv, yv, rectangle.fill_color);
            xv++;
            i++;
        }
        i = 0;
        xv = rectangle.x;
        yv++;
    }
}

void put_circle(t_data data, t_circle circle)
{
    int i = 0;
    int or_x = circle.x;
    int or_y = circle.y;

    for(int y=-circle.radius; y<=circle.radius; y++)
        for(int x=-circle.radius; x<=circle.radius; x++)
            if(circle.x*circle.x+circle.y*circle.y <= circle.radius*circle.radius)
                my_mlx_pixel_put(&data,or_x+x, or_y + circle.y, circle.fill_color);
}

int main()
{
    t_vars vars;
    t_data map;

    int i = 0;
    int x = 0, y = 0;
    int width = 20;
    int height = 10;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
    map.img.mlx_img = mlx_new_image(map.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
    map.img.addr = mlx_get_data_addr(map.img.mlx_img, &map.img.bpp, &map.img.line_len, &map.img.endian);

    mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}