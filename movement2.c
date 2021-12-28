/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <yelatman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 09:21:08 by yelatman          #+#    #+#             */
/*   Updated: 2021/12/28 11:29:33 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	handle_move_up(t_data *data)
{
	move_up(data);
	mlx_clear_window(data->mlx, data->win);
	draw_map(data);
	return (1);
}

int	handle_move_down(t_data *data)
{
	move_down(data);
	mlx_clear_window(data->mlx, data->win);
	draw_map(data);
	return (1);
}

int	handle_move_left(t_data *data)
{
	move_left(data);
	mlx_clear_window(data->mlx, data->win);
	draw_map(data);
	return (1);
}

int	handle_move_right(t_data *data)
{
	move_right(data);
	mlx_clear_window(data->mlx, data->win);
	draw_map(data);
	return (1);
}
