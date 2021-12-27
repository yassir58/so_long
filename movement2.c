/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 09:21:08 by yelatman          #+#    #+#             */
/*   Updated: 2021/12/27 09:23:31 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	handle_move_up(t_data *data)
{
	move_up(data);
	mlx_clear_window(data->mlx, data->win);
	draw_map(data);
}

void	handle_move_down(t_data *data)
{
	move_down(data);
	mlx_clear_window(data->mlx, data->win);
	draw_map(data);
}

void	handle_move_left(t_data *data)
{
	move_left(data);
	mlx_clear_window(data->mlx, data->win);
	draw_map(data);
}

void	handle_move_right(t_data *data)
{
	move_right(data);
	mlx_clear_window(data->mlx, data->win);
	draw_map(data);
}
