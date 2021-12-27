/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <yelatman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 09:04:45 by yelatman          #+#    #+#             */
/*   Updated: 2021/12/27 17:33:57 by yelatman         ###   ########.fr       */
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
	if (keysym == XK_ESCAPE)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	if (data->map.game_over != TRUE)
	{
		if (keysym == XK_UP)
			handle_move_up(data);
		else if (keysym == XK_DOWN)
			handle_move_down(data);
		else if (keysym == XK_LEFT)
			handle_move_left(data);
		else if (keysym == XK_RIGHT)
			handle_move_right(data);
	}
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
	int test = 0;
	if (!check_for_valid_file(argv[argc - 1]))
		ft_putstr_fd("Invalid map file!", 2);
	map_tab = extract_map(argv[argc - 1]);
	test = check_for_valid_map(map_tab);
	if (test)
	{
	init_map(&map, map_tab);
	init_data(&data, map_tab, map);
	draw_map(&data);
	mlx_hook(data.win, KEY_PRESS, 1L << 0, &handle_keypress, &data);
	mlx_loop(data.mlx);
	free(map_tab);
	free(data.mlx);
	}
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Error encountered while processing map !\n", 2);
	free(map_tab);
}
