/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <yelatman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 09:04:45 by yelatman          #+#    #+#             */
/*   Updated: 2021/12/29 21:04:42 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	my_mlx_pixel_put(t_img img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
	*(unsigned int *)dst = color;
}

int	handle_keypress(int keysym, t_data *data)
{
	static int	counter;

	if (keysym == XK_ESCAPE)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	if (data->map.game_over != TRUE)
	{
		ft_putnbr_fd(counter, 1);
		ft_putstr_fd("\n", 1);
		if (keysym == XK_UP)
			counter += handle_move_up(data);
		else if (keysym == XK_DOWN)
			counter += handle_move_down(data);
		else if (keysym == XK_LEFT)
			counter += handle_move_left(data);
		else if (keysym == XK_RIGHT)
			counter += handle_move_right(data);
	}
	return (0);
}

int	handle_leave(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free(data->mlx);
	exit(0);
	return (0);
}

void	put_filled_rect(t_img img, t_rect rectangle)
{
	int	i;
	int	xv;
	int	yv;

	i = 0;
	xv = rectangle.x;
	yv = rectangle.y;
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

int	main(int argc, char *argv[])
{
	t_map	map;
	t_data	data;
	char	**map_tab ;
	int		test;

	map_tab = extract_map(argv[argc - 1]);
	if (validate_map(map_tab, argv[argc - 1]))
	{
		init_map(&map, map_tab);
		init_data(&data, map_tab, map);
		draw_map(&data);
		mlx_hook(data.win, KEY_PRESS, (1L << 0), &handle_keypress, &data);
		mlx_hook(data.win, DESTROY_NOTIFY, (1L << 5), &handle_leave, &data);
		mlx_loop(data.mlx);
		free(map_tab);
		free(data.mlx);
	}
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Error encountered while processing map !\n", 2);
	free(map_tab);
}
