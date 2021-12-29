/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_images_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <yelatman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 10:22:03 by yelatman          #+#    #+#             */
/*   Updated: 2021/12/29 19:51:04 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	display_image(t_data *data, t_vars v)
{
	t_images	img;

	init_images(&img.pl, &img.sp, &img.cn, data);
	init_images_(&img.wl, &img.cd, &img.od, data);
	init_enemy(&img.en, data);
	if (data->map_tab[v.i][v.j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, img.wl.mlx_img, v.x, v.y);
	else if (data->map_tab[v.i][v.j] == '0')
		mlx_put_image_to_window(data->mlx, data->win, img.sp.mlx_img, v.x, v.y);
	else if (data->map_tab[v.i][v.j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, img.cn.mlx_img, v.x, v.y);
	else if (data->map_tab[v.i][v.j] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, img.pl.mlx_img, v.x, v.y);
	else if (data->map_tab[v.i][v.j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, img.cd.mlx_img, v.x, v.y);
	else if (data->map_tab[v.i][v.j] == 'O')
		mlx_put_image_to_window(data->mlx, data->win, img.od.mlx_img, v.x, v.y);
	else if (data->map_tab[v.i][v.j] == 'I')
		mlx_put_image_to_window(data->mlx, data->win, img.en.mlx_img, v.x, v.y);
}
